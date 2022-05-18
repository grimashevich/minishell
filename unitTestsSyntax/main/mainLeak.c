/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLeak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:43:22 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 22:54:09 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

void	test_leak(void);

void	process(void)
{
	check_signal();
	check_timeout();
	test_leak();
	ft_list_remove_all(&g_local.allocated, free);
}

static void	launch(void)
{
	process();
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
		return (OK);
	}
}
