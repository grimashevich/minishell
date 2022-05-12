/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:58:22 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 17:58:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_memory.h"

void	*ft_memcpy(const void *from, void *to, size_t length)
{
	const char	*string_from;
	char		*string_to;
	size_t		i;

	string_from = from;
	string_to = to;
	i = 0;
	while (i < length)
	{
		string_to[i] = string_from[i];
		i += 1;
	}
	return (to);
}
