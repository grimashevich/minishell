/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:40:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 20:10:45 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "envp.h"

t_vars	*delete_var(t_vars *start, char *name);

void	envp_remove(char *variable)
{
	char	*postfix;

	postfix = ft_strjoin(variable, "=");
	if (postfix == NULL)
	{
		perror(NULL);
		exit(1);
	}
	ft_strings_remove_by_part(&g_ms.envp, postfix);
	envp_status();
	free(postfix);
	g_ms.variables = delete_var(g_ms.variables, variable);
}
