/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:35:29 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:06:40 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

char	*get_output(void)
{
	char	buffer[BUFFER];
	char	*output;
	ssize_t	readed;
	int		fd;

	fd = open(g_output_file, O_RDONLY, 0777);
	if (fd == -1)
		exit(TEST_ERROR);
	readed = read(fd, buffer, BUFFER);
	if (readed == -1)
		exit(TEST_ERROR);
	if (close(fd) == -1)
		exit(TEST_ERROR);
	buffer[readed] = '\0';
	output = strdup(buffer);
	if (output == NULL)
		exit(TEST_ERROR);
	return (output);
}
