/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:21:47 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/01 20:20:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	first_cont_pipe(int pipe[2], t_cont *container)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		// dprintf(2, "first_cont_pipe\n");
		// dprintf(2, "pipe[0]: %d\n", pipe[0]);
		// dprintf(2, "pipe[1]: %d\n", pipe[1]);
		dup2(pipe[1], STDOUT_FILENO);
		if (redirects(container->redirects))
			exit(errno);
		close(pipe[0]);
		close(pipe[1]);
		executor(container->tag);
		exit(g_ms.exit_code);
	}
}

pid_t	last_cont_pipe(int pipe[2], t_cont *container)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		// dprintf(2, "last_cont_pipe\n");
		// dprintf(2, "pipe[0]: %d\n", pipe[0]);
		// dprintf(2, "pipe[1]: %d\n", pipe[1]);
		dup2(pipe[0], STDIN_FILENO);
		if (redirects(container->redirects))
			exit(errno);
		close(pipe[0]);
		close(pipe[1]);
		executor(container->tag);
		exit(g_ms.exit_code);
	}
	return (pid);
}

void	cont_pipe(int fd[2][2], t_cont *container)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		// dprintf(2, "cont_pipe\n");
		// dprintf(2, "fd[0][0]: %d\n", fd[0][0]);
		// dprintf(2, "fd[0][1]: %d\n", fd[0][1]);
		// dprintf(2, "fd[1][0]: %d\n", fd[1][0]);
		// dprintf(2, "fd[1][1]: %d\n", fd[1][1]);
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		if (redirects(container->redirects))
			exit(errno);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		executor(container->tag);
		exit(g_ms.exit_code);
	}
}
