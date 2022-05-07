/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:14:43 by EClown            #+#    #+#             */
/*   Updated: 2022/05/07 18:51:49 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_function.h"


static int	cd_error(char *error, int retrn)
{
	ms_error("cd", error, 1);
	return (retrn);
}
/* 
Try to change pwd, return errno from chdir
 */
static int update_pwd(char *new_cwd)
{
	int	errn;

	errn = chdir(new_cwd);
	if (errn != 0)
		ms_error("cd", NULL, errn);
	else
	{
		if (envp_get_value("OLDPWD") == NULL)
			envp_append("OLDPWD", envp_get_value("PWD"));
		else
			envp_replace("OLDPWD", envp_get_value("PWD"));
		envp_replace("PWD", new_cwd);
	}
	return (errn);
}

/*
Return 1 if cwd changed successfully
Return 0 if error has occured
ERRNO = 1 if error has occured
TODO	~
TODO	-
Change current ENVP by "void	envp_replace(char *variable, char *value)"
*/

int	change_direcory(char *new_path)
{
	char	*home_dir;
	char	*old_pwd;
	int		errn;

	if (new_path == NULL || new_path[0] == 0 || ft_is_str_equal(new_path, "~"))
	{
		home_dir = envp_get_value("HOME");
		if (home_dir == NULL)
			return(cd_error("HOME not set", 0));
		errn = update_pwd(home_dir);
		return(! errn);
	}
	else if (ft_is_str_equal(new_path, "-"))
	{
		old_pwd = envp_get_value("OLDPWD");
		errn = update_pwd(old_pwd);
		return(! errn);
	}
	return (! update_pwd(new_path));
}
