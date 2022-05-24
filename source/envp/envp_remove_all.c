/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_remove_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:57:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/24 11:48:32 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "envp.h"

void	envp_remove_all(void)
{
	ft_strings_remove_all(&g_ms.envp);
}
