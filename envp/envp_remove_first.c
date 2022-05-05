/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_remove_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:41:26 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 19:50:29 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "envp.h"

void	envp_remove_first(void)
{
	ft_strings_remove_first(&g_ms.envp);
	envp_status();
}
