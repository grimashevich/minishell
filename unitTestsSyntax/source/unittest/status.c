/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:51:53 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 15:51:51 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

void	return_status(int status)
{
	if (status == TRUE)
	{
		exit(OK);
	}
	else
	{
		exit(KO);
	}
}

void	check_status(void)
{
	int	status;

	wait(&status);
	exit(WEXITSTATUS(status));
}
