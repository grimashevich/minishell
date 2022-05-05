/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_replace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:38:50 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 19:47:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

void	envp_replace(char *variable, char *value)
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
	if (ft_strings_replace_by_part(g_ms.envp, data, postfix) == -1)
	{
		free(data);
	}
	free(postfix);
}
