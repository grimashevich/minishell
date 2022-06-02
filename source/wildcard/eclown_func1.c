/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclown_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:01:55 by EClown            #+#    #+#             */
/*   Updated: 2022/06/01 20:45:26 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

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
int	symb_count_before_char(char c, char *str, char *before)
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
