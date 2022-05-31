/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:13:46 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 08:14:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

//TODO do somthing
static char	**get_path(char **envp, char *command)
{
	char	**path;

	while (*envp != NULL && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(command);
		exit(127);
	}
	path = ft_split(*envp + 5, ':');
	if (path == NULL)
	{
		perror(NULL);
		exit(1);
	}
	return (path);
}

static char	*filejoin(char *command, char *path)
{
	char	*temp;
	char	*file;

	temp = ft_strjoin(path, "/");
	if (temp == NULL)
	{
		perror(NULL);
		exit(1);
	}
	file = ft_strjoin(temp, command);
	if (file == NULL)
	{
		perror(NULL);
		exit(1);
	}
	free(temp);
	return (file);
}

char	*get_file(char *command, char **envp)
{
	char	**path;
	int		i;
	char	*file;

	if (*command == '/' && access(command, 0) == 0)
		return (command);
	if (*command == '.' && access(command, 0) == 0)
		return (command);
	path = get_path(envp, command);
	i = 0;
	file = NULL;
	while (access(file, 0) == -1 && path[i] != NULL)
	{
		free(file);
		file = filejoin(command, path[i++]);
	}
	if (access(file, 0) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	ft_strings_remove_all(&path);
	return (file);
}
