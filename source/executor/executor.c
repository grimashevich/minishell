/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:58:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/28 19:37:24 by ccamie           ###   ########.fr       */
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

	if (access(command, 0) == 0) // bugfix
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

void	redirects(t_rdr_fls *redirects)
{
	int	fd;

	while (redirects != NULL)
	{
		if (redirects->type == WRITE)
		{
			fd = open(redirects->path, O_CREAT | O_TRUNC | O_WRONLY, 0677);
		}
		if (redirects->type == APPEND)
		{
			fd = open(redirects->path, O_CREAT | O_APPEND | O_WRONLY, 0677);
		}
		if (redirects->type == READ)
		{
			fd = open(redirects->path, O_RDONLY);
		}
		// if (redirects->type == HERE_DOC)
		// {
		// 	fd = open(redirects->path, O_CREAT | O_TRUNC | O_RDWR, 0677);
		// }
		if (fd == -1)
		{
			perror("minishell:");
		}
		close(fd); // ban
		redirects = redirects->next;
	}
}

void	first_cont_🍴(int pipe[2], t_cont *container)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipe[1], STDOUT_FILENO);
		close(pipe[0]);
		close(pipe[1]);
		executor(container->tag);
	}
}

pid_t	last_cont_🍴(int pipe[2], t_cont *container)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipe[0], STDIN_FILENO);
		close(pipe[0]);
		close(pipe[1]);
		executor(container->tag);
	}
	return (pid);
}

void	cont_🍴(int fd[2][2], t_cont *container)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		executor(container->tag);
	}
}

void	first_🍴(int pipe[2], t_cmd *command)
{
	pid_t	pid;
	char	*file;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipe[1], STDOUT_FILENO);
		close(pipe[0]);
		close(pipe[1]);
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
}

pid_t	last_🍴(int pipe[2], t_cmd *command)
{
	pid_t	pid;
	char	*file;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipe[0], STDIN_FILENO);
		close(pipe[0]);
		close(pipe[1]);
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
	return (pid);
}

void	🍴(int fd[2][2], t_cmd *command)
{
	pid_t	pid;
	char	*file;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
}

void	minecraft(void)
{
	char	buffer[1025];
	int		fd;
	ssize_t	readed;

	printf("\x1b[32m\n");
	fd = open("minecraft", O_RDONLY);
	readed = read(fd, buffer, 1024);
	while (readed != 0)
	{
		buffer[readed] = '\0';
		write(1, buffer, ft_strlen(buffer));
		readed = read(fd, buffer, 1024);
	}
	printf("\n");
	close(fd);
}

void	juggle_pipes(int arr[2][2])
{
	int	t;

	t = arr[0][0];
	arr[0][0] = arr[1][0];
	arr[1][0] = t;
	t = arr[0][1];
	arr[0][1] = arr[1][1];
	arr[1][1] = t;
}

void	launch_command(t_cmd *command, int fd[2][2], int *number_of_process_for_wait_for_without_of_waitpid)
{
	pid_t	pid;
	char	*file;

	if (command->prev_operator == AND && g_ms.exit_code != 0)
	{
		return ;
	}
	if (command->prev_operator == OR && g_ms.exit_code == 0)
	{
		return ;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	if (command->prev_operator == PIPE)
	{
		if (command->next_operator == PIPE)
		{
			// MIDDLE
			*number_of_process_for_wait_for_without_of_waitpid += 1;
			juggle_pipes(fd);
			pipe(fd[1]);
			🍴(fd, command);
			close(fd[0][0]);
			close(fd[0][1]);
			fd[0][0] = STDIN_FILENO;
			fd[0][1] = STDOUT_FILENO;
		}
		else
		{
			// LAST
			juggle_pipes(fd);
			pid_t	pid = last_🍴(fd[0], command);
			close(fd[0][0]);
			close(fd[0][1]);
			fd[1][0] = STDIN_FILENO;
			fd[1][1] = STDOUT_FILENO;
			waitpid(pid, &g_ms.exit_code, 0);
			while (*number_of_process_for_wait_for_without_of_waitpid > 0)
			{
				wait(NULL);
				*number_of_process_for_wait_for_without_of_waitpid -= 1;
			}
		}
		return ;
	}
	else if (command->next_operator == PIPE)
	{
		// FIRST
		*number_of_process_for_wait_for_without_of_waitpid += 1;
		pipe(fd[1]);
		first_🍴(fd[1], command);
		return ;
	}

























	if (command->redirects != NULL)
	{
		redirects(command->redirects);
	}
	if (command->command[0][0] == '\0')
	{
		if (command->vars != NULL)
		{
			assign_vars_value(command);
			return ;
		}
	}
	if (ft_strcmp(command->command[0], "export") == 0)
	{
		built_export(command->command);
		return ;
	}
	if (ft_strcmp(command->command[0], "exit") == 0)
	{
		built_exit(command->command);
		return ;
	}
	if (ft_strcmp(command->command[0], "unset") == 0)
	{
		built_unset(command->command);
		return ;
	}
	if (ft_strcmp(command->command[0], "cd") == 0)
	{
		g_ms.exit_code = (change_direcory(command->command[1]));
		return ;
	}
	if (ft_strcmp(command->command[0], "pwd") == 0)
	{
		built_pwd();
		return ;
	}
	if (ft_strcmp(command->command[0], "Minecraft") == 0)
	{
		minecraft();
		return ;
	}
	if (ft_strcmp(command->command[0], "echo") == 0)
	{
		built_echo(command->command);
		return ;
	}
	if (ft_strcmp(command->command[0], "env") == 0)
	{
		envp_print();
		g_ms.exit_code = 0;
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
		file = get_file(command->command[0], g_ms.envp);
		execve(file, command->command, g_ms.envp);
	}
	waitpid(pid, &g_ms.exit_code, 0);
}

void	launch_container(t_cont *container, int fd[2][2], int *number_of_process_for_wait_for_without_of_waitpid)
{
	pid_t	pid;
	// int		status;

	(void)number_of_process_for_wait_for_without_of_waitpid;
	if (container->prev_operator == AND && g_ms.exit_code != 0)
	{
		return ;
	}
	if (container->prev_operator == OR && g_ms.exit_code == 0)
	{
		return ;
	}
	(void)fd;







	if (container->prev_operator == PIPE)
	{
		if (container->next_operator == PIPE)
		{
			// MIDDLE
			*number_of_process_for_wait_for_without_of_waitpid += 1;
			juggle_pipes(fd);
			pipe(fd[1]);
			cont_🍴(fd, container);
			close(fd[0][0]);
			close(fd[0][1]);
			fd[0][0] = STDIN_FILENO;
			fd[0][1] = STDOUT_FILENO;
		}
		else
		{
			// LAST
			juggle_pipes(fd);
			pid = last_cont_🍴(fd[0], container);
			close(fd[0][0]);
			close(fd[0][1]);
			fd[1][0] = STDIN_FILENO;
			fd[1][1] = STDOUT_FILENO;
			waitpid(pid, &g_ms.exit_code, 0);
			while (*number_of_process_for_wait_for_without_of_waitpid > 0)
			{
				wait(NULL);
				*number_of_process_for_wait_for_without_of_waitpid -= 1;
			}
		}
		return ;
	}
	else if (container->next_operator == PIPE)
	{
		// FIRST
		*number_of_process_for_wait_for_without_of_waitpid += 1;
		pipe(fd[1]);
		first_cont_🍴(fd[1], container);
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
		waitpid(pid, &g_ms.exit_code, 0);
	}
}

void	executor(t_tag *head)
{
	int	fd[2][2];
	int	number_of_process_for_wait_for_without_of_waitpid;
	int	i;

	i = 0;
	fd[0][0] = 0;
	fd[0][1] = 1;
	fd[1][0] = 0;
	fd[1][1] = 1;
	number_of_process_for_wait_for_without_of_waitpid = 0;
	while (head[i].type != END)
	{
		// NOT creatE pipe
		if (head[i].type == COMMAND)
		{
			launch_command(head[i].data, fd, &number_of_process_for_wait_for_without_of_waitpid);
		}
		else if (head[i].type == CONTAINER)
		{
			launch_container(head[i].data, fd, &number_of_process_for_wait_for_without_of_waitpid);
			exit(g_ms.exit_code);
		}
		i += 1;
	}
}
