/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:12:08 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		
size_t	ft_strlcat(char *from, char *in, size_t lenght)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(from);
	j = ft_strlen(in);
	if (lenght <= j)
		return (lenght + i);
	ft_strlcpy(from, in + j, lenght - j - 1);
	return (i + j);
}
