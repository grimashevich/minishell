/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:36:00 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 13:58:59 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

static void	_check_timeout(void)
{
	sleep(1);
	exit(TIMEOUT);
}

void	check_timeout(void)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, (void *)_check_timeout, NULL) != 0)
	{
		exit(ERROR);
	}
	if (pthread_detach(thread) != 0)
	{
		exit(ERROR);
	}
}