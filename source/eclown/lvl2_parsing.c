/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:04:22 by EClown            #+#    #+#             */
/*   Updated: 2022/05/24 11:59:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_char_in_quotes(char *str, char *c);
void	encode_quotes_str(char *str, char *char2encode);
char	**add_text_to_text(char **dest, char **added, int need_free);
char	**expand_wildcard_arr(char *wildcard);

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
	result->path = path;
	result->out_files =  NULL;
	if (! result->path)
	{
		free(result);
		return (NULL);
	}
	result->fd = fd;
	result->next = NULL;
	return (result);
}

t_rdr_fls *add_last_rdr_file(t_rdr_fls *start, t_rdr_fls *value)
{
	t_rdr_fls	*tmp;

	if (start == NULL && value == NULL)
		return (NULL);
	if (start == NULL)
		return (value);
	if (value == NULL)
		return (start);
	tmp = start;
	while (start->next)
		start = start->next;
	start->next = value;
	return (tmp);
}

void free_rdr(t_rdr_fls *item)
{
	if (item->path)
		free(item->path);
	if (item->out_files)
		ft_free_text(item->out_files);
	free(item);
}

void free_rdr_list(t_rdr_fls *item)
{
	t_rdr_fls *tmp;

	while (item)
	{
		tmp = item->next;
		free_rdr(item);
		item = tmp;
	}
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

int is_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (*(str++) == c)
			return (1);
	}
	return (0);
}

/*
Replace char witch contains in char2encode to its negative variant if it in quotes
*/
void encode_quotes_str(char *str, char *char2encode)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_char_in_str(str[i], char2encode) && is_char_in_quotes(str, &str[i]))
			str[i] *= -1;
		i++;
	}
}

void encode_spcs_quotes_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) && is_char_in_quotes(str, &str[i]))
			str[i] *= -1;
		i++;
	}
}

/*
Nothing to be malloced
Returned tha same pointer
*/
char	*encode_spec_chars_quotes_str(char *str)
{
	int	i;
	int	searched_chars;

	i = 0;
	while (str[i])
	{
		searched_chars = ft_isspace(str[i]) || str[i] == '*';
		searched_chars = searched_chars && is_char_in_quotes(str, &str[i]);
		if (searched_chars)
			str[i] *= -1;
		i++;
	}
	return str;
}


void decode_quotes_str(char *str)
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

	*to_write = NULL;
	if (c == NULL || needle == NULL)
		return (-1);
	i = 0;
	result = 0;
	word_len = 0;
	while (needle[i] && needle[i] == c[i])
		i++;
	while (c[i] && ft_isspace(c[i]))
		_ = word_len >= 0 && i++ == result++;
	while ((c[i] && ! ft_isspace(c[i])) || is_char_in_quotes(&c[i - result], &c[i]))
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

int fd_str_len(int fd, char *fd_str)
{
	int	i;

	if (fd_str != NULL)
		return (ft_strlen(fd_str));
	i = 0;
	while (fd)
	{
		fd = fd / 10;
		i++;
	}
	return (i);
}

/* 
TODO FIX WORKING WITH QUOTES
 */
t_rdr_fls *eject_redirect(char **str, char *c, int rdr_type)
{
	t_rdr_fls	*result;
	char		*fd_str;
	char		*fname;
	int			fd_int;
	int			r_word_len;

	fd_int = get_default_fd_by_rdr_type(rdr_type);
	fd_str = find_num_left_from_char(*str, c);
	if (fd_str)
		fd_int = ft_atoi(fd_str);
	r_word_len = find_word_right_from_needle(c, get_rdr_type(rdr_type), &fname);
	if (r_word_len == -1)
		return (NULL);
	result = create_rdr_fls(fname, fd_int);
	if (! result)
		return (NULL);
	result->type = rdr_type;
	delete_rdr_from_str(str, 
		c - *str - fd_str_len(fd_int, fd_str),
		c - *str + ft_strlen((char *) get_rdr_type(rdr_type)) - 1 + r_word_len);
	if (fd_str)
		free(fd_str);
	return (result);
}

/* 
Search next redirect in str, return type of redirect.
if not found, -1 will be returned
put into *out_start_rdr pointer to first char of found value
 */
int find_next_redirect(char *str, char **out_start_rdr)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		*out_start_rdr = &str[i];
		if (str[i] == '>')
		{
			if (is_char_in_quotes(str, &str[i]))
				continue;
			if (str[i + 1] == '>')
				return (1);
			return (0);
		}
		if (str[i] == '<')
		{
			if (is_char_in_quotes(str, &str[i]))
				continue ;
			if (str[i + 1] == '<')
				return (3);
			return (2);
		}
	}
	return (-1);
}

t_rdr_fls *extract_all_rdrs(char **str)
{
	t_rdr_fls	*result;
	t_rdr_fls	*cur_rdr;
	char		*cur_rdr_start;
	int			cur_rdr_type;

	result = NULL;
	cur_rdr = NULL;
	cur_rdr_start =  NULL;
	while (1)
	{
		cur_rdr_type = find_next_redirect(*str, &cur_rdr_start);
		if (cur_rdr_type == -1)
			return (result);
		cur_rdr = eject_redirect(str, cur_rdr_start, cur_rdr_type);
		result = add_last_rdr_file(result, cur_rdr);
	}
}

void decode_text(char **text)
{
	while (*text)
		decode_quotes_str(*(text++));	
}

void open_quotes_text(char **text)
{
	char	*tmp;

	while (*text)
	{
		tmp = open_quotes(*text);
		if (! tmp)
			ms_error("open_quotes_text", "malloc error", 1);
		free(*text);
		*text = tmp;
		text++;
	}
}

void	extract_wldcrd_rdrs(t_rdr_fls *rdr_start)
{
	char		**splits;
	int			i;
	while (rdr_start)
	{
		encode_spcs_quotes_str(rdr_start->path);
		splits = ft_split(rdr_start->path, ' ');
		if (! splits)
			return ;
		decode_text(splits);
		i = 0;
		while (splits[i])
		{
			rdr_start->out_files = add_text_to_text(
				rdr_start->out_files,
				expand_wildcard_arr(open_quotes(splits[i++])),
				1);
		}
		ft_free_text(splits);
		//open_quotes_text(rdr_start->out_files);
		decode_quotes_str(rdr_start->path);
		rdr_start = rdr_start->next;
	}
}

/*
INPUT:
malloced t_cmd *cmd_struct
*/
void lvl2_parsing(char *cmd_str, t_cmd *cmd_struct)
{
	char	*cmd;
	char	**args;
	char	**tmp;
	int		i;
	char	*str_tmp;

	cmd = ft_strdup(cmd_str);
	if (! cmd)
		return ;
	cmd_struct->redirects = extract_all_rdrs(&cmd);
	extract_wldcrd_rdrs(cmd_struct->redirects);
	// TODO ????. 1.1
	
	encode_quotes_str(cmd, " ");
	tmp = ft_split(cmd, ' ');
	if (tmp == NULL)
	{
		free_rdr_list(cmd_struct->redirects);
		return ;
	}
	free(cmd);
	args = NULL;
	decode_text(tmp);
	i = 0;
	while (tmp[i])
	{
		str_tmp = open_quotes(tmp[i++]);
		args = add_text_to_text(args, expand_wildcard_arr(str_tmp),1);
		//free(str_tmp);
	}
	ft_free_text(tmp);
	//open_quotes_text(args);
	cmd_struct->command = args;
}



void free_t_cmd (t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->command)
		ft_free_text(cmd->command);
	if (cmd->redirects)
		free_rdr_list(cmd->redirects);
	free(cmd);
}

/* 

1. ?????????????????? ?????????????????? (???????????????????? ?? ?????????? ???? ?????????? ?????????????????? ?????????????????????????????? ??????????????????)
	1.1. ?? ???????????? ???????????? ???????????????????? ?????????????????????? ????????????????????
	1.2. ?? ???????????? ???????????? ???????????????????? ?????????????????????? * (?????????????????? ?????? ?? ????????????, ?????? ?????????????? - ?????????????????????? ????????????????????)
	1.3. ?? ???????????? ???????????? ???????????????????? ?????????????????????? ??????????????
2. ???????????????????? ????????????????????
3. ?????????????? ?????? ??????????????, ?????????????????????? ???????????? ??????????????
5. ?????????????? ?????????????? ???? ???????????????? ?? ??????????????????
3. ???????????????????? *
6. ???????????????????? ?????????????? ??????????????
7. ???????????????????? ??????????????

files = file0 file1 file2 file08
var1="*file0*"

0. < infile.txt echo "THE FILES:" *.txt $cFiles > outfile.txt 
1.  echo "1 2 3" *.txt $cFiles
3.	echo "1 2 3" *.txt *.c *.h			($cFiles => *.c *.h)
2.	echo "1_2_3" *.txt *.c *.h
 

??????????????:
???????????????????????? ?????????? ???????????? ?????????????? ???? ???????????? - ???????? ????????????????
?????? ?????????? ?????????? ?????????????????? ??????????????			- ???? ???????? ????????????????????

 */