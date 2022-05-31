/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_pipe_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:35:11 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 09:07:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	child_pipe_middle(t_cmd *command, int *process_up_down, int fd[2][2])
{
	*process_up_down += 1;
	juggle_pipes(fd);
	pipe(fd[1]);
	cmd_pipe(fd, command);
	close(fd[0][0]);
	close(fd[0][1]);
	fd[0][0] = STDIN_FILENO;
	fd[0][1] = STDOUT_FILENO;
}

void	child_pipe_last(t_cmd *command, int *process_up_down, int fd[2][2])
{
	int		status;
	pid_t	pid;

	juggle_pipes(fd);
	pid = last_cmd_pipe(fd[0], command);
	close(fd[0][0]);
	close(fd[0][1]);
	fd[1][0] = STDIN_FILENO;
	fd[1][1] = STDOUT_FILENO;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) != 0)
		g_ms.exit_code = WEXITSTATUS(status);
	else
		g_ms.exit_code = 0;
	unlink(HEREDOC_TMP_FILENAME);
	while (*process_up_down > 0)
	{
		wait(NULL);
		*process_up_down -= 1;
	}
}

void	child_pipe_first(t_cmd *command, int *process_up_down, int fd[2][2])
{
	*process_up_down += 1;
	pipe(fd[1]);
	first_cmd_pipe(fd[1], command);
}
