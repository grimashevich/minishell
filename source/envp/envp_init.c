/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 04:08:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/29 18:42:05 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "envp.h"

void	envp_init(char **envp)
{
	char	*shell_level;
	int		number_of_shell_level;

	g_ms.envp = ft_strings_dup(envp);
	envp_status();
	shell_level = envp_get_value("SHLVL");
	number_of_shell_level = atol(shell_level) + 1;
	if (number_of_shell_level >= 1000)
	{
		number_of_shell_level = 1;
	}
	if (number_of_shell_level < 0)
	{
		number_of_shell_level = 0;
	}
	shell_level = ft_itoa(number_of_shell_level);
	if (shell_level == NULL)
	{
		perror(NULL);
		exit(1);
	}
	envp_replace("SHLVL", shell_level);
	envp_remove("OLDPWD");
	free(shell_level);
}
