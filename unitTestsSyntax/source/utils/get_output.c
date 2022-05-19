/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:59:41 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/18 13:39:29 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

void	read_from_file(int fd, char *buffer)
{
	ssize_t	readed;

	readed = read(fd, buffer, 1024);
	if (readed == -1)
	{
		exit(ERROR);
	}
	else
	{
		buffer[readed] = '\0';
	}
}

char	*get_value_output(void)
{
	char	buffer[1024];
	char	*output;
	int		fd;
	t_list	*element;

	fd = file_open("output.tmp", O_RDONLY);
	read_from_file(fd, buffer);
	file_close(fd);
	output = strdup(buffer);
	element = ft_list_init(output);
	if (element == LIST_FAILED)
	{
		exit(ERROR);
	}
	ft_list_append(&g_local.allocated, element);
	if (output == NULL)
	{
		exit(ERROR);
	}
	else
	{
		return (output);
	}
}
