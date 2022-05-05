/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <stdlib.h>

char	*ft_strdup(char *string)
{
	char	*duplicate;

	duplicate = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (duplicate == NULL)
		return (NULL);
	ft_strcpy(string, duplicate);
	return (duplicate);
}
