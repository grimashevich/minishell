/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:14:43 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 16:45:48 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_function.h"

int		ms_error_free_return(char *msg, char *to_free);
void	exit_if_null(void *pointer);
char	*replace_str_in_str(char *haystack, char *start, int len,
			char *new_str);

static int	cd_error(char *error, int retrn, char *need_free)
{
	if (need_free)
		free(need_free);
	ms_error("cd", error, 1);
	return (retrn);
}

int	check_home_dir(char **new_cwd)
{
	char	*home_dir;

	if (*new_cwd[0] == '~')
	{
		home_dir = envp_get_value("HOME");
		if (home_dir == NULL)
			return (cd_error("HOME not set", 1, NULL));
		*new_cwd = replace_str_in_str(*new_cwd, &(*new_cwd[0]), 1, home_dir);
		exit_if_null(new_cwd);
	}
	else
		*new_cwd = ft_strdup(*new_cwd);
	return (0);
}

/* 
Try to change pwd, return errno from chdir
 */
static int	update_pwd(char *new_cwd)
{
	int		chdir_result;
	char	*cwd;

	if (check_home_dir(&new_cwd))
		return (1);
	chdir_result = chdir(new_cwd);
	if (chdir_result != 0)
		return (ms_error_free_return("cd", new_cwd));
	else
	{
		cwd = getcwd(NULL, MAX_PATH_LEN);
		if (! cwd)
			return (ms_error_free_return("cd: update_pwd", new_cwd));
		if (envp_get_value("OLDPWD") == NULL)
			envp_append("OLDPWD", envp_get_value("PWD"));
		else
			envp_replace("OLDPWD", envp_get_value("PWD"));
		envp_replace("PWD", cwd);
		free(cwd);
	}
	free(new_cwd);
	return (0);
}

int	change_directory2(int *errn, char *tmp)
{
	if (*errn == 0)
	{
		write(1, tmp, ft_strlen(tmp));
		write(1, "\n", 1);
	}
	free(tmp);
	return (*errn);
}

/*
Return 1 if cwd changed successfully
Return 0 if error has occured
ERRNO = 1 if error has occured
Change current ENVP by "void	envp_replace(char *variable, char *value)"
*/
int	change_direcory(char *new_path)
{
	char	*home_dir;
	char	*old_pwd;
	char	*tmp;
	int		errn;

	if (new_path == NULL || new_path[0] == 0 || ft_is_str_equal(new_path, "~"))
	{
		home_dir = envp_get_value("HOME");
		if (home_dir == NULL)
			return (cd_error("HOME not set", 1, NULL));
		errn = update_pwd(home_dir);
		return (errn);
	}
	else if (ft_is_str_equal(new_path, "-"))
	{
		old_pwd = envp_get_value("OLDPWD");
		if (old_pwd == NULL)
			return (cd_error("OLDPWD not set", 1, NULL));
		tmp = ft_strdup(old_pwd);
		exit_if_null(tmp);
		errn = update_pwd(old_pwd);
		return (change_directory2(&errn, tmp));
	}
	return (update_pwd(new_path));
}
