/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_container.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:21:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 20:20:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	set_exit_code(int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 255)
			g_ms.exit_code = 127;
		else
			g_ms.exit_code = WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			g_ms.exit_code = 130;
		else if (WTERMSIG(status) == 3)
			g_ms.exit_code = 131;
		else
			g_ms.exit_code = WEXITSTATUS(status);
	}
	else
		g_ms.exit_code = 0;
}

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

	if (container->next_operator == PIPE)
		return ;
	waitpid(pid, &status, 0);
	signal(SIGINT, signal_new_line);
	signal(SIGQUIT, SIG_IGN);
	set_exit_code(status);
}

void	launch_container(t_cont *container, int fd[2][2], \
	int *process_up_down, int *is_launch)
{
	pid_t	pid;

	if (need_to_go_back_cont(container, process_up_down, fd, is_launch) == TRUE)
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
