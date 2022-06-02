/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:05:45 by EClown            #+#    #+#             */
/*   Updated: 2022/06/03 00:14:39 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eclown_utils.h"

int	get_char_count(char *str, char c)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (*str == c)
			result++;
		str++;
	}
	return (result);
}

char	**clear_and_finish(char **text)
{
	int	i;

	i = 0;
	while (text[i])
		free(text[i]);
	free(text);
	return (NULL);
}

char	**get_pointer_array(char *str, char sep, int words_cnt)
{
	int		i;
	int		j;
	int		n;
	char	**result;

	i = 0;
	result = malloc(sizeof(char *) * (words_cnt + 1));
	if (! result)
		return (NULL);
	while (i <= words_cnt)
		result[i++] = NULL;
	i = 0;
	j = 0;
	while (1)
	{
		n = 0;
		while (str[i++] != sep && str[i - 1] != 0)
			n++;
		result[j++] = malloc(sizeof(char) * (n + 1));
		if (! result[j - 1])
			return (clear_and_finish(result));
		if (str[i - 1] == 0)
			break ;
	}
	return (result);
}

void	fill_array(char **text, char *str, char sep)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			text[n][j] = 0;
			j = 0;
			n++;
			i++;
			continue ;
		}
		text[n][j++] = str[i++];
	}
	text[n][j] = 0;
}

char	**ft_split_new(char *str, char sep)
{
	int		split_cnt;
	char	**result;

	if (str == NULL)
		return (NULL);
	split_cnt = get_char_count(str, sep) + 1;
	result = get_pointer_array(str, sep, split_cnt);
	fill_array(result, str, sep);
	return (result);
}
