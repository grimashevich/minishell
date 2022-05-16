/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 16:40:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

long	get_value_long(char *variable)
{
	char	*temporary;
	long	value;

	temporary = get_value(variable);
	value = atol(temporary);
	free(temporary);
	return (value);
}
