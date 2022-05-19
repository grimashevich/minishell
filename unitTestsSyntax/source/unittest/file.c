/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:50:43 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 23:04:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

int	file_open(char *file, int mode)
{
	char	path[1024];
	int		fd;

	sprintf(path, "%s/%s", g_local.path, file);
	fd = open(path, mode, 0644);
	if (fd == -1)
	{
		exit(ERROR);
	}
	else
	{
		return (fd);
	}
}

void	file_dup2_output(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		exit(ERROR);
	}
}

void	file_close(int fd)
{
	if (close(fd) == -1)
	{
		exit(ERROR);
	}
}
