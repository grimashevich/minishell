/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:34:06 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 14:11:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "../libft.h"

// converts the operand to ascii

int	ft_toascii(int character)
{
	if ((unsigned char)character <= 127)
	{
		return ((unsigned char)(character));
	}
	else
	{
		return ((unsigned char)(character) - 128);
	}
}
