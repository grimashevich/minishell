/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:58:11 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 17:58:12 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_memory.h"

void	*ft_memset(void *pointer, int character, size_t length)
{
	char	*string;
	size_t	i;

	string = pointer;
	i = 0;
	while (i < length)
	{
		string[i] = character;
		i += 1;
	}
	return (pointer);
}
