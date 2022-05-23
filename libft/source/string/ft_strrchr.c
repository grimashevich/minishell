/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		
char	*ft_strrchr(char *string, int character)
{
	unsigned char	uc;
	size_t			slen;

	uc = character;
	slen = ft_strlen(string);
	while (string[slen] != uc && slen)
		slen--;
	if (string[slen] == uc)
		return ((char *)&string[slen]);
	return (NULL);
}
