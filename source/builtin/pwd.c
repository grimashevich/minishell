/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:03:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/27 13:18:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_pwd(void)
{
	char	pwd[4096];

	getcwd(pwd, sizeof(char) * 4096);
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	g_ms.exit_code = 0;
}
