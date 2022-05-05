/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:12:08 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/13 16:53:51 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

size_t	ft_strlcat(char *from, char *in, size_t lenght)
{
	size_t	inlen;
	size_t	fromlen;
	size_t	i;

	inlen = ft_strlen(in);
	fromlen = ft_strlen(from);
	if (lenght <= inlen)
		return (lenght + fromlen);
	lenght -= inlen + 1;
	in += inlen;
	i = 0;
	while (i < lenght && from[i] != '\0')
	{
		in[i] = from[i];
		i += 1;
	}
	in[i] = '\0';
	return (inlen + fromlen);
}
