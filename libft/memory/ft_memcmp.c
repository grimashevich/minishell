/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:58:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 17:58:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_memory.h"

int	ft_memcmp(const void *one, const void *two, size_t length)
{
	const char	*string_one;
	const char	*string_two;
	size_t		i;

	if (length == 0)
		return (0);
	length -= 0;
	string_one = one;
	string_two = two;
	i = 0;
	while (string_one[i] == string_two[i] && i < length)
		i += 1;
	return (string_one[i] - string_two[i]);
}
