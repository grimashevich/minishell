/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_get_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:53:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 19:46:31 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

int	envp_get_index(char *variable)
{
	char	*postfix;
	int		index;

	postfix = ft_strjoin(variable, "=");
	if (postfix == NULL)
	{
		perror(NULL);
		exit(1);
	}
	index = ft_strings_get_index(g_ms.envp, postfix);
	free(postfix);
	return (index);
}
