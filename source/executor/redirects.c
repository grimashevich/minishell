/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:18:29 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 08:32:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	print_redirects_error(char *path)
{
	write(2, "minishell: ", 11);
	write(2, path, ft_strlen(path));
	write(2, ": ", 2);
	perror(NULL);
}

int	redirects(t_rdr_fls *redirects)
{
	int	fd;
	int	exit_code;

	exit_code = 0;
	while (redirects != NULL)
	{
		if (redirects->type == WRITE)
			fd = open(redirects->path, O_CREAT | O_TRUNC | O_WRONLY, 0677);
		else if (redirects->type == APPEND)
			fd = open(redirects->path, O_CREAT | O_APPEND | O_WRONLY, 0677);
		else if (redirects->type == READ)
			fd = open(redirects->path, O_RDONLY);
		else if (redirects->type == HERE_DOC)
			fd = here_doc(redirects->path);
		if (fd == -1)
		{
			print_redirects_error(redirects->path);
			exit_code = errno;
		}
		dup2(fd, redirects->fd);
		close(fd);
		redirects = redirects->next;
	}
	return (exit_code);
}
