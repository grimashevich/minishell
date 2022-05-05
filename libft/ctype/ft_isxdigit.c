/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:34:05 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 14:07:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "../libft.h"

// checks whether the operand is hexadecimal

int	ft_isxdigit(int character)
{
	return ((character >= 48 && character <= 57) + \
			(character >= 65 && character <= 70) + \
			(character >= 97 && character <= 102));
}
