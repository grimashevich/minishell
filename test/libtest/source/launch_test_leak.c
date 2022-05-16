/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test_leak.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:50:00 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:30:16 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	check_signal(void);
void	check_timeout(void);
int		check_test(void);

void	launch_test_leak(void)
{
	int	fd;

	fd = open(g_output_file, O_CREAT | O_WRONLY, 0777);
	dup2(fd, 1);
	check_signal();
	check_timeout();
	check_test();
	close(fd);
}
