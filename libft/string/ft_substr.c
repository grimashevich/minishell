/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:12:04 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 18:46:37 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <stdlib.h>

char	*ft_substr(char *string, size_t start, size_t length)
{
	char	*new;
	size_t	i;

	i = ft_strlen(string);
	if (i < length)
		length = i - start;
	if (start >= i)
		length = 0;
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (new == NULL)
		return (NULL);
	new[length] = '\0';
	ft_strlcpy(string + start, new, length + 1);
	return (new);
}
