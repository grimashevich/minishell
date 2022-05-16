/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_size_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:50 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 16:40:51 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

size_t	get_value_size_t(char *variable)
{
	char	*temporary;
	size_t	value;

	temporary = get_value(variable);
	value = atoll(temporary);
	free(temporary);
	return (value);
}
