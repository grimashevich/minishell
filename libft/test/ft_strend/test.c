/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:46:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:29:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_test(void)
{
	t_data	data;
	int		status;

	data = parser();
	data.returned = ft_strend(data.string, data.ending);
	status = data.returned == data.expected;
	remove_all(data);
	if (status == 1)
		return (0);
	else
		return (1);
}
