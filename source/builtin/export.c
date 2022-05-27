/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:40:34 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/27 15:48:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars *extract_var_assign(char *str, char **out_cmd_wout_assign, int free_old_cmd, t_vars *ms_vars);
void	delete_all_vars(t_vars *start);
char	*get_var_value(t_vars *start, char *name);

void	print_export(void)
{
	char	**envp;
	
	envp = g_ms.envp;
	while (*envp)
	{
		write(1, "declare -x ", 11);
		ft_putendl_fd(*envp, 1);
		envp++;
	}
}

void	local_into_envp(char *name)
{
	char	*value;

	value = get_var_value(g_ms.variables, name);
	if (value != NULL)
	{
		envp_append(name, value);
	}
}

void	append_envp(char *command)
{
	t_vars	*variable;
	char	*out;
	int		index;
	
	variable = extract_var_assign(command, &out, FALSE, NULL);
	if (variable == NULL)
	{
		local_into_envp(out);
	}
	else
	{
		index = envp_get_index(variable->name);
		if (index == -1)
		{
			envp_append(variable->name, variable->value);
		}
		else
		{
			envp_replace_by_index(variable->name, variable->value, index);
		}
		free(out);
		delete_all_vars(variable);
	}
}

void	built_export(char **command)
{
	if (command[1] == NULL)
	{
		print_export();
		g_ms.exit_code = 0;
		return ;
	}
	else
	{
		command++;
		while (*command != NULL)
		{
			append_envp(*command);
			command++;
		}
	}
	g_ms.exit_code = 0;
}