/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_the_diagram.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:24:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/06 20:05:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_diagram(t_tag *head)
{
	t_cont	*container;
	int		i;

	i = 0;
	while (1)
	{
		if (head[i].type == COMMAND)
		{
			printf("\x1b[43m👾\x1b[0m");
		}
		else if (head[i].type == CONTAINER)
		{
			printf("\x1b[42m\x1b[37m📦\x1b[0m");
		}
		else if (head[i].type == END)
		{
			printf("\x1b[41m❌\x1b[0m");
			break ;
		}
		i += 1;
	}
	printf("\n");
	i = 0;
	while (1)
	{
		if (head[i].type == CONTAINER)
		{
			container = (t_cont *)head[i].data;
			print_diagram(container->tag);
		}
		else if (head[i].type == END)
		{
			break ;
		}
		i += 1;
	}
}
