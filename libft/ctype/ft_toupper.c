/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:34:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 14:46:01 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "../libft.h"

// converts the operand to uppercase

int	ft_toupper(int character)
{
	if (character >= 97 && character <= 122)
	{
		return (character - 32);
	}
	else
	{
		return (character);
	}
}
