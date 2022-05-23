/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:46:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:41:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_test(void)
{
	t_data	data;
	int		status;

	data = parser();
	data.returned = ft_substr(data.string, data.start, data.lenght);
	status = strcmp(data.returned, data.expected) == 0;
	remove_all(data);
	if (status == 1)
		return (0);
	else
		return (1);
}
