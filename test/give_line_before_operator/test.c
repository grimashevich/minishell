/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:46:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/10 23:34:25 by ccamie           ###   ########.fr       */
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
		data.returned = give_a_line_before_operator(&line, &prev_op_int);
		if (strcmp(data.returned, *expected++) != 0)
		{
			free(data.returned);
			return (0);
		}
		free(data.returned);
	}
	return (1);
}

int	check_test(void)
{
	t_data	data;
	int		status;

	data = parser();
	status = check(data);
	remove_all(data);
	if (status == 1)
		return (0);
	else
		return (1);
}
