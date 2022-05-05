/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:05 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:06 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

long	ft_atol(char *string)
{
	long long	num;
	long long	sign;

	while (ft_isspace(*string))
		string += 1;
	sign = 1;
	if (*string == 43 || *string == 45)
		if (*string++ == 45)
			sign = -1;
	num = 0;
	while (ft_isdigit(*string))
		num = num * 10 + *string++ - 48;
	return (num * sign);
}
