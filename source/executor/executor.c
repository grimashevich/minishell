/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:58:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 20:03:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	executor_init(int fd[2][2])
{
	fd[0][0] = 0;
	fd[0][1] = 1;
	fd[1][0] = 0;
	fd[1][1] = 1;
}

void	executor(t_tag *head)
{
	int	fd[2][2];
	int	binout[2];
	int	process_up_down;
	int	i;
	int	is_launch;

	i = 0;
	process_up_down = 0;
	while (head[i].type != END)
	{
		binout[0] = dup(0);
		binout[1] = dup(1);
		if (head[i].type == COMMAND)
			launch_command(head[i].data, fd, &process_up_down, &is_launch);
		else if (head[i].type == CONTAINER)
			launch_container(head[i].data, fd, &process_up_down, &is_launch);
		dup2(binout[1], 1);
		dup2(binout[0], 0);
		i += 1;
	}
	unlink(HEREDOC_TMP_FILENAME);
}
