/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:28:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 21:06:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

char	**ft_strings_map(char **strings, char *(*fun)(char *))
{
	char	**map;
	size_t	i;

	map = (char **)malloc((ft_strings_count(strings) + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (strings[i] != NULL)
	{
		map[i] = fun(strings[i]);
		if (map[i] == NULL)
		{
			ft_strings_remove_all(&map);
			return (NULL);
		}
		i += 1;
	}
	map[i] = NULL;
	return (map);
}
