/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:04:22 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:40:26 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

char	*empty_str_instead_null(char *str)
{
	if (! str)
		return (ft_strdup(""));
	return (str);
}

t_vars	*create_var(char *name, char *value)
{
	t_vars	*result;

	result = ft_calloc(1, sizeof(t_vars));
	if (! result)
		return (NULL);
	if (name)
		result->name = ft_strdup(name);
	if (value)
		result->value = ft_strdup(value);
	return (result);
}

t_vars	*add_var_first(t_vars *start, t_vars *new_var)
{
	if (! new_var)
		return (start);
	if (! start)
		return (new_var);
	new_var->next = start;
	return (new_var);
}

void	set_var_global(t_vars *start, char *name)
{
	while (start)
	{
		if (ft_strcmp(start->name, name) == 0)
		{
			start->is_global = 1;
			return ;
		}
		start = start->next;
	}
}

char	*get_var_value(t_vars *start, char *name)
{
	while (start)
	{
		if (ft_strcmp(start->name, name) == 0)
			return (start->value);
		start = start->next;
	}
	return (NULL);
}
