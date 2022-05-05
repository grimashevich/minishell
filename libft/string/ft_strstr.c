/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:12:01 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:12:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;

	while (*haystack != '\0')
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] != '\0')
			i += 1;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack += 1;
	}
	return (NULL);
}
