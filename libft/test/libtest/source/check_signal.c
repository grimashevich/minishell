/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/10 19:04:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"
#include <signal.h>

static void	_check_signal(int signal)
{
	if (signal == SIGABRT)
	{
		exit(SIGABRT);
	}
	if (signal == SIGBUS)
	{
		exit(SIGBUS);
	}
	if (signal == SIGSEGV)
	{
		exit(SIGSEGV);
	}
}

void	check_signal(void)
{
	signal(SIGABRT, _check_signal);
	signal(SIGBUS, _check_signal);
	signal(SIGSEGV, _check_signal);
}
