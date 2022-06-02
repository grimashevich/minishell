/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclown_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:44:02 by EClown            #+#    #+#             */
/*   Updated: 2022/06/01 21:04:21 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

/*
Return how many symbols c in string str from symbol "after"
to end of the string. Return -1 if an error has occured.
*/
int	symb_count_after_char(char c, char *after)
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

static int	is_char_in_quotes2(char *str, char *end)
{
	char	cur_quote;

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
	return (is_char_in_quotes2(str, c));
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
			continue ;
		}
		result[i++] = *(str++);
	}
	result[i] = 0;
	return (result);
}
