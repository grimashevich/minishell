/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:45:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 10:09:35 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	is_pipe_cmd(t_cmd *command, int *process_up_down, int fd[2][2])
{
	if (command->prev_operator == PIPE)
	{
		if (command->next_operator == PIPE)
			child_pipe_middle(command, process_up_down, fd);
		else
			child_pipe_last(command, process_up_down, fd);
		return (TRUE);
	}
	else if (command->next_operator == PIPE)
	{
		child_pipe_first(command, process_up_down, fd);
		return (TRUE);
	}
	if (command->redirects != NULL)
	{
		if (redirects(command->redirects))
		{
			g_ms.exit_code = errno;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	is_variable(t_cmd *command)
{
	if (command->command[0][0] == '\0')
	{
		if (command->vars != NULL)
		{
			assign_vars_value(command);
		}
		if (command->is314159265358979323846 == TRUE)
		{
			write(2, "minishell: : command not found\n", 31);
		}
		return (TRUE);
	}
	return (FALSE);
}

int	is_pipe_cont(t_cont *container, int *process_up_down, int fd[2][2])
{
	if (container->prev_operator == PIPE)
	{
		if (container->next_operator == PIPE)
			chil_pipcont_midd(container, process_up_down, fd);
		else
			chil_pipcont_last(container, process_up_down, fd);
		return (TRUE);
	}
	else if (container->next_operator == PIPE)
	{
		chil_pipcont_first(container, process_up_down, fd);
		return (TRUE);
	}
	return (FALSE);
}
