/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_leak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:59:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/17 14:40:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

void	pre_print(int fd);
void	execute(void);
void	parser(void);
void	print(int fd);
int		compare(void);
void	remove_all(void);

void	test_leak(void)
{
	int	fd;

	parser();
	fd = file_open("output.tmp", O_CREAT | O_TRUNC | O_WRONLY);
	file_dup2_output(fd);
	execute();
	file_close(fd);
	remove_all();
}
