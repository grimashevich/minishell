/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:40:34 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/27 14:41:59 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars *extract_var_assign(char *str, char **out_cmd_wout_assign, int free_old_cmd, t_vars *ms_vars);
void	delete_all_vars(t_vars *start);

void	into_envp(t_vars *variables)
{
	while (variables != NULL)
	{
		envp_append(variables->name, variables->value);
		variables = variables->next;
	}
}

void	built_export(char **command)
{
	char	*string;
	t_vars	*variables;
	char	*out;

	string = ft_strings_to_string(&command[1], " ");
	if (string == NULL)
	{
		perror(NULL);
		exit(1);
	}
	variables = extract_var_assign(string, &out, TRUE, NULL);
	free(out);
	into_envp(variables);
	delete_all_vars(variables);
}
