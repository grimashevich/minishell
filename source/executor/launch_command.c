/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:19:28 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 20:04:01 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	signal_child(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
	}
}

static void	child(t_cmd *command)
{
	char	*file;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	file = get_file(command->command[0], g_ms.envp);
	execve(file, command->command, g_ms.envp);
	exit(1);
}

static void	wait_pid(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	signal(SIGINT, signal_new_line);
	signal(SIGQUIT, SIG_IGN);
	set_exit_code(status);
}

void	launch_command(t_cmd *command, int fd[2][2], int *process_up_down, \
	int *is_launch)
{
	pid_t	pid;

	if (need_to_go_back(command, process_up_down, fd, is_launch) == TRUE)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		exit(1);
	}
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_child);
	if (pid == 0)
		child(command);
	wait_pid(pid);
}
