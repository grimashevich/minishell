/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:59:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/17 16:11:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

void	pre_print(int fd);
void	execute(void);
void	parser(void);
void	print(int fd);
int		compare(void);
void	remove_all(void);

static void	_pre_print(void)
{
	int	fd;

	fd = file_open("log.tmp", O_CREAT | O_TRUNC | O_WRONLY);
	dprintf(fd, "\t\t------------------------------\n");
	pre_print(fd);
	dprintf(fd, "\t\t------------------------------\n");
	file_close(fd);
}

static void	_print(void)
{
	int	fd;

	fd = file_open("log.tmp", O_CREAT | O_TRUNC | O_WRONLY);
	dprintf(fd, "\t\t------------------------------\n");
	print(fd);
	dprintf(fd, "\t\t------------------------------\n");
	file_close(fd);
}

int	test(void)
{
	int	status;
	int	fd;

	parser();
	_pre_print();
	fd = file_open("output.tmp", O_CREAT | O_TRUNC | O_WRONLY);
	file_dup2_output(fd);
	execute();
	file_close(fd);
	status = compare();
	_print();
	remove_all();
	return (status);
}
