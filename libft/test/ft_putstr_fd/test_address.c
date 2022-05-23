/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_address.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:46:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:34:01 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_test(void)
{
	t_data	data;

	data = parser();
	data.returned = ft_putchar_fd(data.string, data.fd);
	remove_all(data);
	return (0);
}
