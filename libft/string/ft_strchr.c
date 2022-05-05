/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

char	*ft_strchr(char *string, char character)
{
	while (*string != character && *string != '\0')
		string += 1;
	if (*string == character)
		return ((char *)string);
	return (NULL);
}
