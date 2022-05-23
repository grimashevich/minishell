/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:29:28 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/10 23:30:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	print_test_address(void)
{
	int	status;

	wait(&status);
	status = WEXITSTATUS(status);
	if (status == 0)
		printf("\x1b[32mADDRESS\x1b[0m ");
	else if (status == SIGABRT)
		printf("\x1b[33mADDRESS\x1b[0m ");
	else if (status == SIGBUS)
		printf("\x1b[33mADDRESS\x1b[0m ");
	else if (status == SIGSEGV)
		printf("\x1b[33mADDRESS\x1b[0m ");
	else if (status == TEST_TIMEOUT)
		printf("\x1b[33mTIMEOUT\x1b[0m ");
	else if (status == TEST_ERROR)
		printf("\x1b[33mTEST ERROR\x1b[0m ");
	else
		printf("\x1b[31mKO\x1b[0m ");
	exit(status);
}
