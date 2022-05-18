/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:42:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 16:03:42 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

void	process(void)
{
	int		status;

	check_signal();
	check_timeout();
	status = test();
	ft_list_remove_all(&g_local.allocated, free);
	return_status(status);
}

static void	launch(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		exit(ERROR);
	}
	if (pid == 0)
	{
		process();
	}
	else
	{
		check_status();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		return (ERROR);
	}
	else
	{
		g_local.allocated = NULL;
		g_local.path = argv[1];
		g_local.test = argv[2];
		launch();
	}
}
