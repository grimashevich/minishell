/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:28:27 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/25 19:02:09 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_print(char **command)
{
	char	*line;
	
	line = ft_strings_to_string(command, " ");
	if (line == NULL)
	{
		perror(NULL);
		exit(1);
	}
	write(1, line, ft_strlen(line));
	free(line);
}

void	built_echo(char **command)
{
	if (command[1] != NULL && ft_strcmp(command[1], "-n") == 0)
	{
		if (command[2] != NULL)
		{
			echo_print(&command[2]);
		}
		g_ms.exit_code = 0;
	}
	else
	{
		if (command[1] != NULL)
		{
			echo_print(&command[1]);
		}
		write(1, "\n", 1);
		g_ms.exit_code = 0;
	}
}
