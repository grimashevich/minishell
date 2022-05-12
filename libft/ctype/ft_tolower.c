/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:34:08 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 14:46:04 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "../libft.h"

// converts the operand to lowercase

int	ft_tolower(int character)
{
	if (character >= 65 && character <= 90)
	{
		return (character + 32);
	}
	else
	{
		return (character);
	}
}
