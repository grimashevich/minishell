/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:34:01 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Checks whether the operand is punctuation.
int	ft_ispunct(int character)
{
	return ((character >= 33 && character <= 47) + \
			(character >= 58 && character <= 64) + \
			(character >= 91 && character <= 96) + \
			(character >= 123 && character <= 126));
}
