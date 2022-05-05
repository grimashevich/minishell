/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:31:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 19:46:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

void	envp_append(char *variable, char *value)
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
	ft_strings_append(&g_ms.envp, data);
	envp_status();
}
