/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:40:27 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 18:32:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

size_t	ft_strlcpy(char *from, char *to, size_t lenght)
{
	size_t	tolenght;
	size_t	i;

	tolenght = ft_strlen(to);
	if (lenght == 0)
		return (tolenght);
	lenght -= 1;
	i = 0;
	while (i < lenght && from[i] != '\0')
	{
		to[i] = from[i];
		i += 1;
	}
	to[i] = '\0';
	return (tolenght);
}
