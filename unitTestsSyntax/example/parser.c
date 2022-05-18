/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:00:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/18 16:59:22 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	parser(void)
{
	g_data.id = get_value_int("TEST");
	g_data.string = get_value_string("STRING");
	g_data.returned = 0;
	g_data.expected_returned = get_value_int("RETURNED");
	g_data.expected_output = get_value_string("OUTPUT");
	g_data.isoutput = TRUE;
	g_data.isreturned = TRUE;
}
