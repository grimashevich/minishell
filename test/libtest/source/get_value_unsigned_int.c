/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:47 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 16:40:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

unsigned int	get_value_unsigned_int(char *variable)
{
	char			*temporary;
	unsigned int	value;

	temporary = get_value(variable);
	value = atol(temporary);
	free(temporary);
	return (value);
}
