/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:25:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		
char	*ft_strnstr(char *haystack, char *needle, size_t lenght)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && lenght--)
	{
		i = 0;
		while (haystack[i] == needle[i] && i <= lenght && needle[i] != '\0')
			i += 1;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack += 1;
	}
	return (NULL);
}
