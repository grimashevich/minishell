/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:32:44 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 15:12:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

static void	check_signal_abrt(int signal)
{
	if (signal == SIGABRT)
	exit(signal);
}

static void	check_signal_bus(int signal)
{
	if (signal == SIGBUS)
	exit(signal);
}

static void	check_signal_segv(int signal)
{
	if (signal == SIGSEGV)
		exit(signal);
}

void	check_signal(void)
{
	signal(SIGABRT, check_signal_abrt);
	signal(SIGBUS, check_signal_bus);
	signal(SIGSEGV, check_signal_segv);
}
