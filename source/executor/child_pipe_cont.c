/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_pipe_cont.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:53:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/01 20:16:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	chil_pipcont_last(t_cont *container, int *process_up_down, int fd[2][2])
{
	int		status;
	pid_t	pid;

	juggle_pipes(fd);
	pid = last_cont_pipe(fd[0], container);
	printf("Minecraft\n");
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

void	chil_pipcont_midd(t_cont *container, int *process_up_down, int fd[2][2])
{
	*process_up_down += 1;
	juggle_pipes(fd);
	pipe(fd[1]);
	cont_pipe(fd, container);
	close(fd[0][0]);
	close(fd[0][1]);
	fd[0][0] = STDIN_FILENO;
	fd[0][1] = STDOUT_FILENO;
}

void	chil_pipcont_first(t_cont *container, int *process_up_down, \
	int fd[2][2])
{
	*process_up_down += 1;
	pipe(fd[1]);
	first_cont_pipe(fd[1], container);
}
