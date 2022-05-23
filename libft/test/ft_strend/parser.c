/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:06:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:28:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_data	parser(void)
{
	t_data	data;

	data.string = get_value("STRING");
	data.ending = get_value("ENDING");
	data.returned = 0;
	data.expected = get_value_int("EXPECTED");
	return (data);
}
