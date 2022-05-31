/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:56:38 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 04:58:32 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_tcmd(t_cmd *cmd);
void	print_rdr(t_rdr_fls *item);

void	print_operator(int operator)
{
	if (operator == AND)
	{
		printf("\x1b[35m&&\x1b[0m");
	}
	else if (operator == OR)
	{
		printf("\x1b[35m||\x1b[0m");
	}
	else if (operator == PIPE)
	{
		printf("\x1b[35m|\x1b[0m");
	}
	else if (operator == SEQUENCE)
	{
		printf("\x1b[35m;\x1b[0m");
	}
	else if (operator == EMPTY)
	{
		printf("\x1b[35m-\x1b[0m");
	}
}

void	print_tree(t_tag *head)
{
	t_cont		*container;
	t_cmd		*command;
	t_rdr_fls	*rdr;
	int			i;
	int			j;

	i = 0;
	while (1)
	{
		if (head[i].type == COMMAND)
		{
			command = head[i].data;
			print_operator(command->prev_operator);
			j = 0;
			while (command->command[j] != NULL)
			{
				printf("\x1b[34m %s\x1b[0m", command->command[j]);
				j += 1;
			}
			printf(" ");
			rdr = command->redirects;
			while (rdr != NULL)
			{
				if (rdr->type == WRITE)
					printf("\x1b[33m> \x1b[0m");
				if (rdr->type == APPEND)
					printf("\x1b[33m>> \x1b[0m");
				if (rdr->type == READ)
					printf("\x1b[33m< \x1b[0m");
				if (rdr->type == HERE_DOC)
					printf("\x1b[33m<< \x1b[0m");
				printf("\x1b[33m%s \x1b[0m", rdr->path);
				rdr = rdr->next;
			}
			print_operator(command->next_operator);
		}
		else if (head[i].type == CONTAINER)
		{
			container = head[i].data;
			print_operator(container->prev_operator);
			printf(" (");
			print_tree(container->tag);
			printf(") ");
			rdr = container->redirects;
			while (rdr != NULL)
			{
				if (rdr->type == WRITE)
					printf("\x1b[33m> \x1b[0m");
				if (rdr->type == APPEND)
					printf("\x1b[33m>> \x1b[0m");
				if (rdr->type == READ)
					printf("\x1b[33m< \x1b[0m");
				if (rdr->type == HERE_DOC)
					printf("\x1b[33m<< \x1b[0m");
				printf("\x1b[33m%s \x1b[0m", rdr->path);
				rdr = rdr->next;
			}
			print_operator(container->next_operator);
		}
		else if (head[i].type == END)
		{
			break ;
		}
		i += 1;
	}
}

void	print_tcont(t_cont *container)
{
	int			i;
	t_rdr_fls	*tmp_rdr;

	i = 0;
	printf("\nCONTAINER:\n---\n");
	printf("REDIRECTS:\n");
	tmp_rdr = container->redirects;
	while (tmp_rdr)
	{
		printf("%2d:", i++);
		print_rdr(tmp_rdr);
		tmp_rdr = tmp_rdr->next;
	}
}

void	print_cmd(t_tag *head)
{
	int		i;
	t_cont	*container;

	i = 0;
	while (1)
	{
		if (head[i].type == COMMAND)
		{
			print_tcmd(head[i].data);
		}
		else if (head[i].type == END)
		{
			break ;
		}
		i += 1;
	}
	i = 0;
	while (1)
	{
		if (head[i].type == CONTAINER)
		{
			container = (t_cont *)head[i].data;
			print_tcont(container);
			print_cmd(container->tag);
		}
		else if (head[i].type == END)
		{
			break ;
		}
		i += 1;
	}
}
