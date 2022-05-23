/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_leak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:46:18 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:33:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check(t_data data)
{
	char	*line;
	char	**expected;
	int		prev_op_int;

	line = data.line;
	expected = data.expected;
	prev_op_int = 0;
	while (*line != '\0')
	{
		data.returned = give_a_line_before_operator(&data.line, &prev_op_int);
		free(data.returned);
	}
	return (1);
}

int	check_test(void)
{
	t_data	data;

	data = parser();
	check(data);
	remove_all(data);
	return (0);
}
