/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:44 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <stdlib.h>

char	*ft_strjoin(char *one, char *two)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = ft_strlen(one);
	j = ft_strlen(two);
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(one, new);
	ft_strcpy(two, new + i);
	new[i + j] = '\0';
	return (new);
}
