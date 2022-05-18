/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:59:43 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 14:57:40 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

int	get_value_int(char *variable)
{
	char	*temporary;
	int		value;

	temporary = get_value_string(variable);
	value = atoi(temporary);
	ft_list_remove_last(&g_local.allocated, free);
	return (value);
}
