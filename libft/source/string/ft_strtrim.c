/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:12:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		
char	*ft_strtrim(char *string, char *set)
{
	size_t	lenght;

	while (*string && ft_strchr(set, *string))
		string += 1;
	lenght = ft_strlen(string);
	while (lenght != 0 && ft_strchr(set, string[lenght]) != NULL)
		lenght -= 1;
	return (ft_substr(string, 0, lenght + 1));
}
