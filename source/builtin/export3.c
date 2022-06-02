/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:19:17 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 22:30:24 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*extract_var_assign(char *str, char **out_cmd_wout_assign,
			int free_old_cmd, t_vars *ms_vars);
void	delete_all_vars(t_vars *start);
char	*get_var_value(t_vars *start, char *name);
void	set_var_global(t_vars *start, char *name);
void	free_var(t_vars *item);
t_vars	*extract_var_assign(char *str, char **out_cmd_wout_assign,
			int free_old_cmd, t_vars *ms_vars);
t_vars	*create_var(char *name, char *value);
t_vars	*add_var_first(t_vars *start, t_vars *new_var);
t_vars	*delete_var(t_vars *start, char *name);
int		free_var_and_return(t_vars *var, int result);
void	append_envp(char *command);
int		check_and_concat(char *arg);
void	print_export(void);
void	exit_if_null(void *pointer);

int	if_in_var_without_value(char **var_value, char **new_var_name, t_vars *tmp)
{
	char	*tmp_str;

	*var_value = get_var_value(g_ms.variables, *new_var_name);
	if (*var_value == NULL)
	{
		free_var(tmp);
		tmp = create_var(*new_var_name, "");
		tmp->is_global = 1;
		g_ms.variables = add_var_first(g_ms.variables, tmp);
		return (1);
	}
	if (*var_value[0] == '\0')
		return (free_var_and_return(tmp, 1));
	tmp_str = ft_strjoin3(*new_var_name, "=", *var_value);
	exit_if_null(tmp_str);
	append_envp(tmp_str);
	free(tmp_str);
	return (free_var_and_return(tmp, 1));
}

int	add_global_local_var(char *arg)
{
	t_vars	*tmp;
	char	*var_value;
	char	*new_var_name;

	if (check_and_concat(arg))
		return (1);
	var_value = NULL;
	tmp = extract_var_assign(arg, NULL, 0, g_ms.variables);
	if (tmp == NULL)
		new_var_name = arg;
	else
		new_var_name = tmp->name;
	if (ft_strchr(arg, '='))
	{
		g_ms.variables = delete_var(g_ms.variables, new_var_name);
		return (free_var_and_return(tmp, 0));
	}
	if (tmp == NULL || tmp->value[0] == '\0')
		if_in_var_without_value(&var_value, &new_var_name, tmp);
	g_ms.variables = delete_var(g_ms.variables, new_var_name);
	return (0);
}

int	is_normal_var_name(char *var_name)
{
	int	i;

	if (! var_name)
		return (0);
	if (var_name[0] != '_' && ! ft_isalpha(var_name[0]))
		return (0);
	i = 1;
	while (var_name[i] && var_name[i] != '=' && var_name[i] != '+')
	{
		if (! (ft_isalnum(var_name[i]) || var_name[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static void	print_exp_set_ec_to_0(void)
{
	print_export();
	g_ms.exit_code = 0;
}

void	built_export(char **command)
{
	if (command[1] == NULL)
		return (print_exp_set_ec_to_0());
	else
	{
		command++;
		while (*command != NULL)
		{
			if (! is_normal_var_name(*command))
			{
				write(2, "minishell: export: ", 19);
				write(2, *command, ft_strlen(*command));
				write(2, ": not a valid identifier\n", 25);
			}
			else
			{
				if (! add_global_local_var(*command))
					append_envp(*command);
			}
			command++;
		}
	}
	g_ms.exit_code = 0;
}
