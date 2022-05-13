/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:04:22 by EClown            #+#    #+#             */
/*   Updated: 2022/05/13 22:08:58 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

int	is_char_in_quotes(char *str, char *c);

int str_is_numeric(char *str)
{
	if (str == NULL || *str == 0)
		return (0);
	while (*str)
	{
		if (! ft_isdigit(*(str++)))
			return (0);
	}
	return (1);
}

t_rdr_fls	*create_rdr_fls(char *path, int fd)
{
	t_rdr_fls	*result;

	if (path == NULL && path[0] == 0)
		return (NULL);
	result = malloc(sizeof(t_rdr_fls));
	if (! result)
		return (NULL);
	result->path = ft_strdup(path);
	if (! result->path)
	{
		free(result);
		return (NULL);
	}
	result->fd = fd;
	result->next = NULL;
	return (result);
}

void add_last_rdr_file(t_rdr_fls *start, t_rdr_fls *value)
{
	if (start == NULL)
		return ;
	while (start->next)
		start = start->next;
	start->next = value;
}

/*
return new string with deleted chars from start index to end index (included)
*/
char* del_from_str(char *str, int start, int end)
{
	int		strlen;
	char	*result;
	int		i;
	int		j;

	strlen = ft_strlen(str);
	if (str == NULL || strlen - 1 < end - start || end < 0 || start < 0)
		return (NULL);
	result = malloc(sizeof(char) * (strlen - (end - start)));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i < start || i > end)
			result[j++] = str[i];
		i++;
	}
	result[j] = 0;
	return (result);
}

/*
Replace char > and < to its negative variant if it in quotes
*/
void encode_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '>' || str[i] == '<') && is_char_in_quotes(str, &str[i]))
			str[i] *= -1;
		i++;
	}
}

void decode_str(char *str)
{
	while (*str)
	{
		if (*str < 0)
			*str *= -1;
		str++;
	}
}

/*

Return malloced copy of left word from  char c
	if this word is numeric and if no space
	between char c and word
*/
char *find_num_left_from_char(char *str, char *c)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	if (str == NULL || c == NULL)
		return (NULL);
	i = -1;
	len = 0;
	while (str <= &c[i] && ! ft_isspace(c[i]))
	{
		if (! ft_isdigit(c[i]))
			return (NULL);
		i--;
		len++;
	}
	if (len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (len + 1));
	i++;
	j = 0;
	while (i < 0)
		result[j++] = c[i++];
	result[j] = 0;
	return (result);
}

/* 
Trying to find next word after needle in some string
c - is pointer to first character of needle
RETURN count of chars from end of the needle to end of the first word
	copy (malloced) finded word to pointer *_to_write
 */

int find_word_right_from_needle(char *c, const char *needle, char **to_write)
{
	int	result;
	int	word_len;
	int	i;
	int	_;

	if (c == NULL || needle == NULL)
		return (-1);
	i = 0;
	result = 0;
	word_len = 0;
	while (needle[i] && needle[i] == c[i])
		i++;
	while (c[i] && ft_isspace(c[i]))
		_ = word_len >= 0 && i++ == result++;
	while (c[i] && ! ft_isspace(c[i]))
		_ = 0 <= word_len++ && i++ == result++;
	if (word_len == 0)
		return (-1);
	*to_write = ft_substr(c, i - word_len, word_len);
	return (result);
}

char *get_rdr_type(int type)
{
	if (type == WRITE)
		return (">");
	if (type == APPEND)
		return (">>");
	if (type == READ)
		return ("<");
	if (type == HERE_DOC)
		return ("<<");
	return ("");
}

int get_default_fd_by_rdr_type(int type)
{
	if (type < 2)
		return (1);
	return (0);
}

void delete_rdr_from_str(char **str, int start, int end)
{
	char	*tmp;

	tmp = del_from_str(*str, start, end);
	if (! tmp)
		return ;
	free(*str);
	*str = tmp;
}

t_rdr_fls *eject_redirect(char **str, char *c, int rdr_type)
{
	t_rdr_fls	*result;
	char		*fd_str;
	char		*fname;
	int			fd_int;
	const char	*str_rdr;
	int			r_word_len;

	str_rdr = get_rdr_type(rdr_type);
	fd_int = get_default_fd_by_rdr_type(rdr_type);
	fd_str = find_num_left_from_char(*str, c);
	if (fd_str)
		fd_int = ft_atoi(fd_str);
	r_word_len = find_word_right_from_needle(c, str_rdr, &fname);
	if (r_word_len == -1)
		return (NULL);
	result = create_rdr_fls(fname, fd_int);
	if (! result)
		return (NULL);
	delete_rdr_from_str(str, 
		c - *str - ft_strlen(fd_str),
		c - *str + ft_strlen((char *) str_rdr) - 1 + r_word_len);
	return (result);
}

/* ehco abc 2 >> error.log */

/*

012345678

123 abc>>  some word
i = 		7
result = 	6
word_len = 	4

 */

/* 
void extract_redirect(char *str, int start, enum Rdr_type type)
{
	char	search_rdr[3];

	search_rdr[2] = 0;
	if (type == WRITE || type == APPEND)
		search_rdr[0] = '>';
	else if (type == READ || type == HERE_DOC)
		search_rdr[0] = '<';
	
} */




/* 
Fill
arr[0] - for input
arr[0] for output
if redirectes found ins str, the function will change given string.
	It will remove resirectes from string.

EXAMPLE:
	INPUT str = "< in.txt echo 1 > out.txt"
	arr[0] = "in.txt"
	arr[1] = "out.txt"
	str = "echo 1"
 */

/* void	extract_redirects(char *str, t_cmd *cmd)
{
	char	**result;

	
}
 */

/* void parse_lvl2(t_cmd *cmd, char *cmd_str)
{
	char	*str;
	char	tmp;
	char	**redirects;

	str = ft_strdup(cmd_str);
	extract_redirects(str, cmd);
	tmp = str;
	str = ft_strtrim(str, " \t\n");
	free(tmp);
	
} */