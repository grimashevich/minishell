/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:18:29 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 20:01:03 by ccamie           ###   ########.fr       */
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

int	redirects_count(t_rdr_fls *redirects)
{
	int	i;

	i = 0;
	while (redirects != NULL)
	{
		i += 1;
		redirects = redirects->next;
	}
	return (i);
}

int	get_redirects_fd(t_rdr_fls *redirects, int *exit_code)
{
	int	fd;

	if (redirects->type == WRITE)
		fd = open(redirects->path, O_CREAT | O_TRUNC | O_WRONLY, 0677);
	else if (redirects->type == APPEND)
		fd = open(redirects->path, O_CREAT | O_APPEND | O_WRONLY, 0677);
	else if (redirects->type == READ)
		fd = open(redirects->path, O_RDONLY);
	else
		fd = here_doc(redirects->path);
	if (fd == -1)
	{
		print_redirects_error(redirects->path);
		*exit_code = errno;
	}
	return (fd);
}

void	redirects_dup2(t_rdr_fls *redirects, int *fd, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dup2(fd[i], redirects->fd);
		close(fd[i]);
		redirects = redirects->next;
		i += 1;
	}
	free(fd);
}

int	redirects(t_rdr_fls *redirects)
{
	int			*fd;
	int			exit_code;
	int			i;
	int			count;
	t_rdr_fls	*start;

	exit_code = 0;
	count = redirects_count(redirects);
	fd = (int *)malloc(count * sizeof(int));
	if (fd == NULL)
		exit(1);
	i = 0;
	start = redirects;
	while (redirects != NULL)
	{
		fd[i] = get_redirects_fd(redirects, &exit_code);
		i += 1;
		redirects = redirects->next;
	}
	redirects_dup2(start, fd, count);
	return (exit_code);
}
