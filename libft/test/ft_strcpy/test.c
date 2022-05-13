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

int	check_test(void)
{
	t_data	data;
	int		status;

	data = parser();
	ft_strcpy(data.from, data.to);
	status = strcmp(data.to, data.expected) == 0;
	remove_all(data);
	if (status == 1)
		return (0);
	else
		return (1);
}
