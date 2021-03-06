/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:51:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/24 11:48:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "envp.h"

void	envp_print(void)
{
	if (ft_strings_print(g_ms.envp) == -1)
	{
		perror(NULL);
		exit(1);
	}
}
