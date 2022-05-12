/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_strings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:13:06 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:13:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static size_t	get_count(char *string, char *splitter)
{
	size_t	count;
	int		lenght;

	count = 1;
	lenght = ft_strlen(splitter);
	while (*string != '\0')
	{
		if (ft_strncmp(string, splitter, lenght) == 0)
		{
			string += lenght;
			count += 1;
		}
		else
		{
			string += 1;
		}
	}
	return (count);
}

static int	fill_in_strings(char **strings, char *string, char *splitter)
{
	int	i;
	int	lenght;

	lenght = ft_strlen(splitter);
	i = 0;
	while (string[i] != '\0')
	{
		if (ft_strncmp(string, splitter, lenght) == 0)
		{
			*strings = ft_substr(string, 0, i);
			if (*strings == NULL)
				return (-1);
			string += lenght + i;
			i = 0;
		}
		else
		{
			i += 1;
		}
	}
	return (0);
}

char	**ft_string_to_strings(char *string, char *splitter)
{
	size_t	count;
	char	**strings;

	if (string == NULL)
		return (NULL);
	if (splitter == NULL)
		return (NULL);
	count = get_count(string, splitter);
	strings = (char **)malloc((count + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	if (fill_in_strings(strings, string, splitter) == -1)
	{
		ft_strings_remove_all(&strings);
		return (NULL);
	}
	return (strings);
}
