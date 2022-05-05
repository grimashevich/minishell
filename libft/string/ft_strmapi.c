/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:39:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:19:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <stdlib.h>

char	*ft_strmapi(char *string, char (*func)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	map = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (string[i] != '\0')
	{
		map[i] = func(i, string[i]);
		i += 1;
	}
	map[i] = '\0';
	return (map);
}
