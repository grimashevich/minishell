/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 04:08:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/06 19:15:01 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

void	envp_init(char **envp)
{
	g_ms.envp = ft_strings_dup(envp);
	envp_status();
}
