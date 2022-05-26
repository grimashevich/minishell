/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:58:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/26 21:31:12 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static char	**get_path(char **envp, char *command)
{
	char	**path;

	while (*envp != NULL && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == NULL)
	{
		// access(command, 0);
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

static char	*get_file(char *command, char **envp)
{
	char	**path;
	int		i;
	char	*file;

	if (access(command, 0) == 0)
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

void	built_unset(char **command)
{
	command++;
	while (*command != NULL)
	{
		envp_remove(*command);
		command++;
	}
}

void assign_vars_value(t_cmd *command)
{
	int	index;

	if (command->command[0][0] != '\0')
		return ;
	index = envp_get_index(command->vars->name);
	if (index != -1)
	{
		envp_replace_by_index(command->vars->name, command->vars->value, index);
	}
	else
	{
		g_ms.variables = update_vars(g_ms.variables, command->vars->name, command->vars->value);
	}
}

void	launch_command(t_cmd *command)
{
	pid_t	pid;
	char	*file;
	int		status;

	if (command->prev_operator == AND && g_ms.exit_code != 0)
	{
		return ;
	}
	if (command->prev_operator == OR && g_ms.exit_code == 0)
	{
		return ;
	}
	// if (command->next_operator == PIPE)
	// {
	// 	pipe(*fifo[0]);
	// 	pipe(*fifo[1]);
	// }
	assign_vars_value(command);
	if (strcmp(command->command[0], "exit") == 0)
	{
		built_exit(command->command);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		exit(1);
	}
	if (pid == 0)
	{
		// int	fd;

		// fd = get_fd(command->redirects);
		// if (fd == -1)
		// {
		// 	dup2(0, fifo[0])
		// }
		if (strcmp(command->command[0], "echo") == 0)
		{
			built_echo(command->command);
			return ;
		}
		if (strcmp(command->command[0], "cd") == 0)
		{
			change_direcory(command->command[1]);
			return ;
		}
		if (strcmp(command->command[0], "env") == 0)
		{
			envp_print();
			return ;
		}
		if (strcmp(command->command[0], "unset") == 0)
		{
			built_unset(command->command);
			return ;
		}
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
	waitpid(pid, &status, 0);
	g_ms.exit_code = status;
}

void	launch_container(t_cont *container)
{
	pid_t	pid;
	int		status;

	if (container->prev_operator == AND && g_ms.exit_code != 0)
	{
		return ;
	}
	if (container->prev_operator == OR && g_ms.exit_code == 0)
	{
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		exit(1);
	}
	if (pid == 0)
	{
		executor(container->tag);
	}
	if (container->next_operator != PIPE)
	{
		waitpid(pid, &status, 0);
		g_ms.exit_code = status;
	}
}

// int get_fd

void	executor(t_tag *head)
{
	// int	fifo[2][2];
	int	i;

	i = 0;
	// fifo[0][0] = 0;
	// fifo[0][1] = 1;
	// fifo[1][0] = 0;
	// fifo[1][1] = 1;
	while (head[i].type != END)
	{
		// NOT creatE pipe
		if (head[i].type == COMMAND)
		{
			launch_command(head[i].data);
		}
		else if (head[i].type == CONTAINER)
		{
			launch_container(head[i].data);
		}
		i += 1;
	}
}
