/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:12:18 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 10:12:42 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	need_to_go_back_cont(t_cont *container, int *process_up_down, int fd[2][2])
{
	if (container->prev_operator == AND && g_ms.exit_code != 0)
		return (TRUE);
	if (container->prev_operator == OR && g_ms.exit_code == 0)
		return (TRUE);
	if (is_pipe_cont(container, process_up_down, fd) == TRUE)
		return (TRUE);
	return (FALSE);
}

void	juggle_pipes(int arr[2][2])
{
	int	t;

	t = arr[0][0];
	arr[0][0] = arr[1][0];
	arr[1][0] = t;
	t = arr[0][1];
	arr[0][1] = arr[1][1];
	arr[1][1] = t;
}

int	need_to_go_back(t_cmd *command, int *process_up_down, int fd[2][2])
{
	if (command->prev_operator == AND && g_ms.exit_code != 0)
		return (TRUE);
	if (command->prev_operator == OR && g_ms.exit_code == 0)
		return (TRUE);
	if (is_pipe_cmd(command, process_up_down, fd) == TRUE)
		return (TRUE);
	if (is_variable(command) == TRUE)
		return (TRUE);
	if (built_in(command) == TRUE)
		return (TRUE);
	return (FALSE);
}
