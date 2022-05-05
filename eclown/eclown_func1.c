/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclown_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:01:55 by EClown            #+#    #+#             */
/*   Updated: 2022/05/04 19:53:49 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ec_str_copy(char *str, int cut_start, int cut_end)
{
	int		str_len;
	int		result_str_len;
	char	*result;
	int		i;

	str_len = ft_strlen(str);
	if (cut_start + cut_end > str_len)
		return (NULL);
	result_str_len = str_len - cut_start - cut_end;
	result = malloc(result_str_len + 1);
	if (! result)
		return (NULL);
	i = 0;
	while (i < result_str_len)
	{
		result[i] = str[i + cut_start];
		i++;
	}
	result[i] = 0;
	return (result);
}

int	find_last_char(char *str, char c)
{
	int	result;
	int	i;

	i = 0;
	result = -1;
	while (str[i])
	{
		if (str[i] == c)
			result = i;
		i++;
	}
	return (result);
}

int	find_first_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && ! is_char_in_quotes(str, &(str[i])))
			return (i);
		i++;
	}
	return (-1);
}

int	get_lines_count(char **text)
{
	int	n;

	n = 0;
	while (text[n])
		n++;
	return (n);
}

/*
Return how many symbols c in string str from start to symbol "before"
or to end of the string. Return -1 if an error has occured.
*/
int symb_count_before_char(char c, char *str, char *before)
{
	int	result;

	result = 0;
	if (str == NULL || str > &c || before == NULL)
		return (-1);
	while (*str && str < before)
	{
		if (*str == c)
			result++;
		str++;
	}
	return (result);
}

/*
Return how many symbols c in string str from symbol "after"
to end of the string. Return -1 if an error has occured.
*/
int symb_count_after_char(char c, char *after)
{
	int	result;

	result = 0;
	if (after == NULL)
		return (-1);
	after++;
	while (*after)
	{
		if (*after == c)
			result++;
		after++;
	}
	return (result);
}

static int is_char_in_quotes2(char *str, char *end)
{
	char cur_quote;

	cur_quote = 0;
	while (*str)
	{
		if (cur_quote == 0 && (*str == '"' || *str == '\''))
			cur_quote = *str;
		else if (cur_quote == *str)
				cur_quote = 0;
		str++;
		if (str >= end)
			return (cur_quote);
	}
	return (0);
}

/* 
return 1 if char is in closed quotes
return 0 if:
			char is not in quotes 
			quotes are not closed
			an error has occurred
 */
// case "tes"*"file"
// case abc"'"*"'"def
int	is_char_in_quotes(char *str, char *c)
{
	int		str_len;

	if (str == NULL || *str == 0 || c == NULL || c <= str)
		return (0);
	str_len = ft_strlen(str);
	if (c >= &str[str_len])
		return (0);
	return is_char_in_quotes2(str, c);
}

char	*remove_quotes(char *str)
{
	int		i;
	char	*result;

	if (str == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (! result)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
		{
			str++;
			continue;
		}
		result[i++] = *(str++);
	}
	result[i] = 0;
	return (result);
}

static int open_quotes2(char *str_char, char *cur_char)
{
	int	result;

	result = 0;
	if (*str_char == *cur_char)
		*cur_char = 0;
	else if (*cur_char == 0 && *str_char == '"')
		*cur_char = '"';
	else if (*cur_char == 0 && *str_char == '\'')
		*cur_char = '\'';
	else
		result = 1;
	return (result);
}

char	*open_quotes(char *str)
{
	char	cur_char;
	char	*result;
	int		i;

	if (str == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	cur_char = 0;
	while (*str)
	{
		if (open_quotes2(str, &cur_char))
			result[i++] = *str;
		str++;
	}
	result[i] = 0;
	return (result);
}