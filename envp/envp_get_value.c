/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_get_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:31:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 20:08:37 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

char	*envp_get_value(char *variable)
{
	char	*postfix;
	char	*string;

	postfix = ft_strjoin(variable, "=");
	if (postfix == NULL)
	{
		perror(NULL);
		exit(1);
	}
	string = ft_strings_get_string(g_ms.envp, postfix);
	free(postfix);
	if (string == NULL)
	{
		return (NULL);
	}
	else
	{
		string += ft_strlen(variable) + 1;
		return (string);
	}
}
