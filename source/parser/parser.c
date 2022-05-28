/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/28 19:10:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	iscommand(char *line)
{
	while (*line != '\0')
	{
		if (*line == '(')
		{
			return (FALSE);
		}
		else
		{
			line += 1;
		}
	}
	return (TRUE);
}

void	fill_the_current_level(char *line, t_tag *head, int number_of_commands)
{
	char	*part;
	int		prev_op_int;
	int		i;

	prev_op_int = 0;
	i = 0;
	while (i < number_of_commands)
	{
		part = give_a_line_before_operator(&line, &prev_op_int);
		if (iscommand(part) == TRUE)
		{
			remove_insignificant_spases(&part);
			head[i].type = COMMAND;
			head[i].data = get_command(part);
		}
		else
		{
			remove_insignificant_spases(&part);
			head[i].type = CONTAINER;
			head[i].data = get_container(part);
		}
		free(part);
		i += 1;
	}
	head[i].type = END;
}

t_tag	*create_the_current_level(char *line)
{
	t_tag	*head;
	int		number_of_operators;
	int		number_of_commands;

	number_of_operators = count_the_number_of_operators(line);
	number_of_commands = number_of_operators + 1;
	head = (t_tag *)malloc((number_of_commands + 1) * sizeof(t_tag));
	if (head == NULL)
	{
		perror("minishell");
		exit(1);
	}
	fill_the_current_level(line, head, number_of_commands);
	return (head);
}


t_tag	*create_tree(char *line)
{
	t_tag	*head;

	remove_insignificant_spases(&line);
	// remove_insignificant_brackets(&line);
	head = create_the_current_level(line);
	free(line);
	return (head);
}

t_tag	*parser(char *line)
{
	t_tag	*head;
	int		i;

	i = 0;
	while (line[i] != '#' && line[i] != '\0')
		i += 1;
	line = ft_substr(line, 0, i);
	if (line == NULL)
	{
		perror("minishell)");
		exit(1);
	}
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	if (check_syntax(line) != 0)
	{
		return (NULL);
	}
	head = create_tree(line);
	return (head);
}
