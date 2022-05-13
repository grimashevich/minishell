/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:06:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:40:56 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_data	parser(void)
{
	t_data	data;

	data.string = get_value("STRING");
	data.start = get_value_size_t("START");
	data.lenght = get_value_size_t("LENGHT");
	data.returned = NULL;
	data.expected = get_value("EXPECTED");
	return (data);
}
