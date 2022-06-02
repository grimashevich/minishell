/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:25:50 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 16:29:38 by EClown           ###   ########.fr       */
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
void	local_into_envp(char *name, char *to_free);

/*
Make from string: 	a=   word 1   word 2   
this string:		a="   word 1   word 2   "
*/
char	*string_with_spaces_crutch(char *arg)
{
	char	*result;
	int		i;

	if (arg == NULL || ! ft_strchr(arg, '='))
		return (NULL);
	result = malloc(ft_strlen(arg) + 3);
	if (! result)
		return (NULL);
	i = 0;
	while (arg[i] != '=')
	{
		result[i] = arg[i];
		i++;
	}
	result[i++] = '=';
	result[i++] = '"';
	while (arg[i - 1])
	{
		result[i] = arg[i - 1];
		i++;
	}
	result[i++] = '"';
	result[i] = 0;
	return (result);
}

void	append_envp(char *command)
{
	t_vars	*variable;
	char	*out;
	int		index;
	char	*tmp;

	tmp = string_with_spaces_crutch(command);
	variable = extract_var_assign(tmp, &out, FALSE, NULL);
	free(tmp);
	tmp = variable->value;
	variable->value = open_quotes(tmp);
	free(tmp);
	if (variable == NULL)
		local_into_envp(out, out);
	else
	{
		index = envp_get_index(variable->name);
		if (index == -1)
			envp_append(variable->name, variable->value);
		else
			envp_replace_by_index(variable->name, variable->value, index);
		free(out);
		g_ms.variables = delete_var(g_ms.variables, variable->name);
		delete_all_vars(variable);
	}
}

int	free_var_and_return(t_vars *var, int result)
{
	free_var(var);
	return (result);
}

void	move_var_from_env_to_internal(char *name)
{
	char	*value;
	t_vars	*tmp_var;

	if (name == NULL)
		return ;
	value = envp_get_value(name);
	if (value == NULL)
		return ;
	value = ft_strdup(value);
	envp_remove(name);
	g_ms.variables = delete_var(g_ms.variables, name);
	tmp_var = create_var(name, value);
	free(value);
	tmp_var->is_global = 1;
	g_ms.variables = add_var_first(g_ms.variables, tmp_var);
}

int	check_and_concat(char *arg)
{
	char	*concat_addr;
	char	*old_value;
	char	*new_value;
	char	*var_name;

	concat_addr = ft_strstr(arg, "+=");
	if (! concat_addr || is_char_in_quotes(arg, concat_addr))
		return (0);
	var_name = ft_substr(arg, 0, concat_addr - arg);
	move_var_from_env_to_internal(var_name);
	old_value = get_var_value(g_ms.variables, var_name);
	new_value = ft_strjoin(old_value, concat_addr + 2);
	g_ms.variables = update_vars(g_ms.variables, var_name, new_value);
	free(var_name);
	free(new_value);
	return (1);
}
