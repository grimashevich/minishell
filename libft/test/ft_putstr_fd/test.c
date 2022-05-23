/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:46:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:36:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_test(void)
{
	t_data	data;
	int		status;

	data = parser();
	data.returned = ft_putstr_fd(data.string, data.fd);
	status = data.returned == data.expected;
	if (status != 1)
	{
		remove_all(data);
		return (1);
	}
	data.output = get_output();
	status = strcmp(data.output, data.expected_output) == 0;
	remove_all(data);
	if (status == 1)
		return (0);
	else
		return (1);
}
