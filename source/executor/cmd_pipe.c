/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:29:39 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 16:19:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	pid_active(pid_t pid)
{
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	first_cmd_pipe(int pipe[2], t_cmd *command)
{
	pid_t	pid;
	char	*file;

	pid = fork();
	pid_active(pid);
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		dup2(pipe[1], STDOUT_FILENO);
		if (redirects(command->redirects))
			exit(1);
		close(pipe[0]);
		close(pipe[1]);
		if (built_in(command) == TRUE)
			exit(g_ms.exit_code);
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
}

pid_t	last_cmd_pipe(int pipe[2], t_cmd *command)
{
	pid_t	pid;
	char	*file;

	pid = fork();
	pid_active(pid);
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		dup2(pipe[0], STDIN_FILENO);
		if (redirects(command->redirects))
			exit(errno);
		close(pipe[0]);
		close(pipe[1]);
		if (built_in(command) == TRUE)
		{
			exit(g_ms.exit_code);
		}
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
	return (pid);
}

static void	ft_close_fd(int fd[2][2])
{
	(void)fd;
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
}

void	cmd_pipe(int fd[2][2], t_cmd *command)
{
	pid_t	pid;
	char	*file;

	pid = fork();
	pid_active(pid);
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		if (redirects(command->redirects))
			exit(errno);
		ft_close_fd(fd);
		if (built_in(command) == TRUE)
		{
			exit(g_ms.exit_code);
		}
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
}
