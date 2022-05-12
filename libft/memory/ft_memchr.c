/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:58:26 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 17:58:27 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_memory.h"

void	*ft_memchr(void *pointer, int character, size_t length)
{
	char	*string;
	size_t	i;

	string = pointer;
	i = 0;
	while (string[i] != character && i < length)
		i += 1;
	if (string[i] != character)
		return (&pointer[i]);
	else
		return (NULL);
}
