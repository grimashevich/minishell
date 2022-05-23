/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:50:05 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:30:12 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	check_signal(void);
void	check_timeout(void);
int		check_test(void);

void	launch_test(void)
{
	pid_t	pid;
	int		status;
	int		fd;

	pid = fork();
	if (pid < 0)
	{
		exit(TEST_ERROR);
	}
	if (pid == 0)
	{
		fd = open(g_output_file, O_CREAT | O_WRONLY, 0777);
		if (fd == -1)
			exit(TEST_ERROR);
		dup2(fd, 1);
		check_signal();
		check_timeout();
		status = check_test();
		if (close(fd) == -1)
			exit(TEST_ERROR);
		exit(status);
	}
}
