/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:41:38 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 22:43:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_cmd(t_cmd *cmd);

void	remove_tree(t_tag *head)
{
	t_cont	*container;
	t_tag	*start;
	t_tag	*tag;
	int		i;

	i = 0;
	start = head;
	while (head[i].type != END)
	{
		if (head[i].type == COMMAND)
		{
			free_t_cmd(head[i].data);
		}
		else if (head[i].type == CONTAINER)
		{
			container = head[i].data;
			tag = container->tag;
			free(container);
			remove_tree(tag);
		}
		i += 1;
	}
	free(start);
}
