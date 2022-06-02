/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:40:34 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 22:20:37 by EClown           ###   ########.fr       */
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

void	print_var_export_name(char *name)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd("\n", 1);
}

void	print_empty_vars(void)
{
	t_vars	*tmp;

	tmp = g_ms.variables;
	while (tmp)
	{
		if (tmp->is_global)
			print_var_export_name(tmp->name);
		tmp = tmp->next;
	}
}

void	print_export(void)
{
	char	**envp;
	int		i;

	envp = g_ms.envp;
	while (*envp)
	{
		write(1, "declare -x ", 11);
		i = 0;
		while ((*envp)[i] != '\0' && (*envp)[i] != '=')
			i += 1;
		i++;
		write(1, *envp, i);
		ft_putchar_fd('\"', 1);
		write(1, *envp + i, ft_strlen(*envp + i));
		ft_putchar_fd('\"', 1);
		ft_putchar_fd('\n', 1);
		envp++;
	}
	print_empty_vars();
}

void	local_into_envp(char *name, char *to_free)
{
	char	*value;

	value = get_var_value(g_ms.variables, name);
	if (value != NULL)
	{
		envp_append(name, value);
	}
	if (to_free)
		free(to_free);
}
