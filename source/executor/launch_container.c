/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_container.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:21:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 19:25:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	child(t_cont *container)
{
	if (redirects(container->redirects))
		exit(errno);
	executor(container->tag);
	exit(g_ms.exit_code);
}

static void	wait_pid(t_cont *container, pid_t pid)
{
	int	status;

	if (container->next_operator != PIPE)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) != 0)
			g_ms.exit_code = WEXITSTATUS(status);
		else
			g_ms.exit_code = 0;
	}
}

void	launch_container(t_cont *container, int fd[2][2], int *process_up_down)
{
	pid_t	pid;

	if (need_to_go_back_cont(container, process_up_down, fd) == TRUE)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		exit(1);
	}
	if (pid == 0)
	{
		child(container);
	}
	wait_pid(container, pid);
}
