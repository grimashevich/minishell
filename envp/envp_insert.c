/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 04:12:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 20:25:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

void	envp_insert(char *variable, char *value, int index)
{
	char	*postfix;
	char	*data;

	postfix = ft_strjoin(variable, "=");
	if (postfix == NULL)
	{
		perror(NULL);
		exit(1);
	}
	data = ft_strjoin(postfix, value);
	if (data == NULL)
	{
		perror(NULL);
		exit(1);
	}
	free(postfix);
	ft_strings_insert(&g_ms.envp, data, index);
	envp_status();
}
