/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_vars_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:38:46 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 08:18:04 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	assign_vars_value(t_cmd *command)
{
	int	index;

	index = envp_get_index(command->vars->name);
	if (index != -1)
	{
		envp_replace_by_index(command->vars->name, command->vars->value, index);
	}
	else
	{
		g_ms.variables = update_vars(g_ms.variables, command->vars->name, \
			command->vars->value);
	}
}
