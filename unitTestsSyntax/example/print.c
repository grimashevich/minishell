/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:00:18 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/18 17:00:59 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	pre_print(int fd)
{
	dprintf(fd, "\t\t \x1b[37m\x1b[40m input:    %-16s \x1b[0m\n", \
		g_data.string);
	dprintf(fd, "\t\t \x1b[37m expected: \x1b[1m\x1b[33m%-16s \x1b[0m\n", \
		g_data.expected_output);
	dprintf(fd, "\t\t \x1b[37m expected: \x1b[1m\x1b[33m%-16d \x1b[0m\n", \
		g_data.expected_returned);
}

void	print(int fd)
{
	dprintf(fd, "\t\t \x1b[37m\x1b[1m test:     %d \x1b[0m\n", g_data.id);
	dprintf(fd, "\t\t \x1b[37m\x1b[40m input:    %-16s \x1b[0m\n", \
		g_data.string);
	dprintf(fd, "\t\t \x1b[37m expected: \x1b[1m\x1b[33m%-16s \x1b[0m\n", \
		g_data.expected_output);
	if (g_data.isoutput == TRUE)
		dprintf(fd, "\t\t \x1b[37m output:   \x1b[1m\x1b[32m%-16s \x1b[0m\n", \
			g_data.output);
	else
		dprintf(fd, "\t\t \x1b[41m output:   \x1b[37m%-16s \x1b[0m\n", \
			g_data.output);
	dprintf(fd, "\t\t \x1b[37m expected: \x1b[1m\x1b[33m%-16d \x1b[0m\n", \
		g_data.expected_returned);
	if (g_data.isreturned == TRUE)
		dprintf(fd, "\t\t \x1b[37m returned: \x1b[1m\x1b[32m%-16d \x1b[0m\n", \
			g_data.returned);
	else
		dprintf(fd, "\t\t \x1b[41m returned: \x1b[37m%-16d \x1b[0m\n", \
			g_data.returned);
}
