/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_replace_by_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:58:56 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 20:20:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

void	envp_replace_by_index(char *variable, char *value, int index)
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
	free(postfix);
	if (data == NULL)
	{
		perror(NULL);
		exit(1);
	}
	ft_strings_replace(g_ms.envp, data, index);
}
