/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:12:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/12 19:02:06 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

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