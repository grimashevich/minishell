/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:36:50 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

void	decode_quotes_str(char *str)
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
char	*find_num_left_from_char(char *str, char *c)
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

int	find_word_right_from_needle(char *c, const char *needle, char **to_write)
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
		_ = (word_len >= 0 && i++ == result++);
	while ((c[i] != '>' && c[i] && ! ft_isspace(c[i]))
		|| is_char_in_quotes(&c[i - result], &c[i]))
		_ = (0 <= word_len++ && i++ == result++);
	if (word_len == 0)
		return (-1);
	*to_write = ft_substr(c, i - word_len, word_len);
	return (result);
}

char	*get_rdr_type(int type)
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

int	get_default_fd_by_rdr_type(int type)
{
	if (type < 2)
		return (1);
	return (0);
}
