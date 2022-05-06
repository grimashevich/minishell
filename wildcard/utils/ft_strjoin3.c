/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:25:12 by EClown            #+#    #+#             */
/*   Updated: 2022/05/06 13:30:01 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eclown_utils.h"

char	*ft_strjoin3(char *str1, char *str2, char *str3)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(str1, str2);
	if (! tmp)
		return (NULL);
	result = ft_strjoin(tmp, str3);
	free(tmp);
	return (result);
}
