/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:58:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 17:58:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_memory.h"

void	*ft_memmove(const void *from, void *to, size_t length)
{
	const char	*string_from;
	char		*string_to;

	if (to < from)
	{
		ft_memcpy(from, to, length);
	}
	else if (to > from)
	{
		string_from = from;
		string_to = to;
		while (length != 0)
		{
			length -= 1;
			string_to[length] = string_from[length];
		}
	}
	return (to);
}
