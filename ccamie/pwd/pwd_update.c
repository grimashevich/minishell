/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:55:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:19:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#define FALSE	0
#define TRUE	1
#define EMPTY	NULL

static char	*get_oldpwd(void)
{
	char	*oldpwd;

	oldpwd = envp_get_value("PWD");
	if (oldpwd == EMPTY)
	{
		oldpwd = ft_strdup("");
	}
	else
	{
		oldpwd = ft_strdup(oldpwd);
	}
	if (oldpwd == NULL)
	{
		perror(NULL);
		exit(1);
	}
	return (oldpwd);
}

static void	create_oldpwd(void)
{
	char	*oldpwd;

	oldpwd = get_oldpwd();
	envp_append("OLDPWD", oldpwd);
	free(oldpwd);
}

static void	update_oldpwd(void)
{
	char	*oldpwd;

	oldpwd = get_oldpwd();
	envp_replace("OLDPWD", oldpwd);
	free(oldpwd);
}

static void	update(char *current_working_directory)
{
	envp_replace("PWD", current_working_directory);
	// free(current_working_directory);
}

void	pwd_update(char *current_working_directory)
{
	static int	oldpwd_is_empty = TRUE;

	if (oldpwd_is_empty == TRUE)
	{
		oldpwd_is_empty = FALSE;
		create_oldpwd();
	}
	else
	{
		update_oldpwd();
	}
	update(current_working_directory);
}
