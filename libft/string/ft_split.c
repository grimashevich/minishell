/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:22 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <stdlib.h>

static size_t	get_count(char *string, int splitter)
{
	size_t	count;

	count = 0;
	while (*string != '\0')
	{
		if (*string != splitter)
			count += 1;
		while (*string != splitter && *string != '\0')
			string += 1;
		while (*string == splitter && *string != '\0')
			string += 1;
	}
	return (count);
}

static int	fill_in_strings(char *string, int splitter, char **strings)
{
	int	i;

	while (*string != '\0')
	{
		while (*string == splitter && *string != '\0')
			string += 1;
		i = 0;
		while (string[i] != splitter && string[i] != '\0')
			i += 1;
		if (i != 0)
		{
			*strings = ft_substr(string, 0, i);
			if (*strings == NULL)
				return (-1);
			strings++;
			string += i;
		}
	}
	*strings = NULL;
	return (0);
}

char	**ft_split(char *string, int splitter)
{
	char	**strings;
	size_t	count;

	count = get_count(string, splitter);
	strings = (char **)malloc((count + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	if (fill_in_strings(string, splitter, strings) == -1)
	{
		ft_strings_remove_all(&strings);
		return (NULL);
	}
	return (strings);
}
