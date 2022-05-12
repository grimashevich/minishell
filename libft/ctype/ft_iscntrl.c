/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:55 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 14:02:36 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "../libft.h"

// checks whether the operand is a control character

int	ft_iscntrl(int character)
{
	return ((character >= 0 && character <= 31) || character == 127);
}
