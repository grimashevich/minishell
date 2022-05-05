/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:56 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

int	ft_strncmp(char *one, char *two, size_t length)
{
	size_t	i;

	if (length == 0)
		return (0);
	length -= 1;
	i = 0;
	while (i < length && one[i] == two[i] && one[i] != '\0')
		i += 1;
	return ((unsigned char)one[i] - (unsigned char)two[i]);
}
