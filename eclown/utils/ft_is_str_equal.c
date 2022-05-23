/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:44:49 by EClown            #+#    #+#             */
/*   Updated: 2022/05/06 18:07:52 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eclown_utils.h"

/* 
Compare 2 strings
Return 1: if str1 == str2 (by symbols, not by memory)
Return 0: if not. If any error has occured. If any str is NULL
 */

int	ft_is_str_equal(char *str1, char *str2)
{
	int	result;
	
	if (str1 == NULL || str2 == NULL)
		return (0);
	result = ft_strcmp(str1, str2);
	if (result == 0)
		return (1);
	return (0);
}
