/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:31:23 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

t_vars	*get_var_by_name(t_vars *start, char *name)
{
	while (start)
	{
		if (ft_strcmp(start->name, name) == 0)
			return (start);
		start = start->next;
	}
	return (NULL);
}

void	free_var(t_vars *item)
{
	if (! item)
		return ;
	if (item->name)
		free(item->name);
	if (item->value)
		free(item->value);
	free(item);
}

t_vars	*delete_var(t_vars *start, char *name)
{
	t_vars	*prev;
	t_vars	*tmp;
	t_vars	*cur;

	if (start == NULL)
		return (NULL);
	if (ft_strcmp(name, start->name) == 0)
	{
		tmp = start->next;
		free_var(start);
		return (tmp);
	}
	cur = start;
	while (cur)
	{
		if (ft_strcmp(cur->name, name) == 0)
		{
			prev->next = cur->next;
			free_var(cur);
			return (start);
		}
		prev = cur;
		cur = cur->next;
	}
	return (start);
}

void	delete_all_vars(t_vars *start)
{
	while (start)
	{
		start = delete_var(start, start->name);
	}
}

t_vars	*update_vars(t_vars *start, char *name, char *new_value)
{
	t_vars	*tmp;
	t_vars	*old_var;
	char	*tmp_str;

	old_var = get_var_by_name(g_ms.variables, name);
	if (old_var && old_var->is_global == 1)
	{
		tmp_str = ft_strjoin3(name, "=", new_value);
		append_envp(tmp_str);
		free(tmp_str);
		return (g_ms.variables);
	}
	tmp = delete_var(start, name);
	return (add_var_first(tmp, create_var(name, new_value)));
}
