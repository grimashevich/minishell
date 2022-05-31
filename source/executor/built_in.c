/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:56:00 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 08:02:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	minecraft(void)
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

int	built_in(t_cmd *command)
{
	if (ft_strcmp(command->command[0], "export") == 0)
		built_export(command->command);
	else if (ft_strcmp(command->command[0], "exit") == 0)
		built_exit(command->command);
	else if (ft_strcmp(command->command[0], "unset") == 0)
		built_unset(command->command);
	else if (ft_strcmp(command->command[0], "cd") == 0)
		g_ms.exit_code = (change_direcory(command->command[1]));
	else if (ft_strcmp(command->command[0], "pwd") == 0)
		built_pwd();
	else if (ft_strcmp(command->command[0], "Minecraft") == 0)
		minecraft();
	else if (ft_strcmp(command->command[0], "echo") == 0)
		built_echo(command->command);
	else if (ft_strcmp(command->command[0], "env") == 0)
	{
		envp_print();
		g_ms.exit_code = 0;
	}
	else
		return (FALSE);
	return (TRUE);
}
