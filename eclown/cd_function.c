/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:14:43 by EClown            #+#    #+#             */
/*   Updated: 2022/05/06 21:19:44 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_function.h"


static int	cd_error(char *error, int retrn)
{
	ms_error("cd", error, 1);
	return (retrn);
}

/*
Return 1 if cwd changed successfully
Return 0 if error has occured
ERRNO = 1 if error has occured
do	~
do	-
Change current ENVP by "void	envp_replace(char *variable, char *value)"
*/

int	change_direcory(char *new_path)
{
	char	*cwd;
	char	*home_dir;
	int		errn;

	if (new_path == NULL || ft_is_str_equal(new_path, "~"))
	{
		home_dir = envp_get_value("HOME");
		if (home_dir == NULL)
			return(cd_error("HOME not set", 0));
		errn = chdir(home_dir);
		if (errn != 0)
			ms_error("cd", NULL, errn);
		return(! errn);
	}
	if (ft_is_str_equal(new_path, "-"))
	{
		//TODO Останавился тут
		// prev dir
	}
	else
	{
		// other dirs
	}

	cwd = getcwd(NULL, MAX_PATH_LEN);
	printf("%s\n", cwd);
	return (1);
}