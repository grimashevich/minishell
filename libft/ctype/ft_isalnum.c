/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 14:02:24 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "../libft.h"

// checks whether the operand is alphanumeric

int	ft_isalnum(int character)
{
	return ((character >= 48 && character <= 57) + \
			(character >= 65 && character <= 90) + \
			(character >= 97 && character <= 122));
}
