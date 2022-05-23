/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:43 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 16:40:44 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

int	get_value_int(char *variable)
{
	char	*temporary;
	int		value;

	temporary = get_value(variable);
	value = atoi(temporary);
	free(temporary);
	return (value);
}
