/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:06:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 17:42:20 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_data	parser(void)
{
	t_data	data;
	char	*expected;

	data.line = get_value("LINE");
	data.returned = NULL;
	expected = get_value("EXPECTED");
	data.expected = ft_split(expected, '.');
	free(expected);
	return (data);
}
