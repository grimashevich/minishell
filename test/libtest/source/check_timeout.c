/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_timeout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:22 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/10 19:04:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"
#include <pthread.h>

static void	*_check_timeout(void *pointer)
{
	sleep(1);
	exit(TEST_TIMEOUT);
	return (pointer);
}

void	check_timeout(void)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, _check_timeout, NULL) != 0)
		exit(TEST_ERROR);
	if (pthread_detach(thread) != 0)
		exit(TEST_ERROR);
}
