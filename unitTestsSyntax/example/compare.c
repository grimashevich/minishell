/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:00:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 15:59:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	compare(void)
{
	if (g_data.returned == g_data.expected_returned)
	{
		g_data.isreturned = TRUE;
	}
	else
	{
		g_data.isreturned = FALSE;
	}
	if (strcmp(g_data.output, g_data.expected_output) == 0)
	{
		g_data.isoutput = TRUE;
	}
	else
	{
		g_data.isoutput = FALSE;
	}
	if (g_data.isreturned == TRUE && g_data.isoutput == TRUE)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
