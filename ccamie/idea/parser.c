/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/05 19:50:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_the_syntax(char *line);
void	remove_insignificant_spases(char **line);
void	remove_insignificant_brackets(char **line);
int		count_the_number_of_operators(char *line);

t_tag	*create_the_current_level(char *line)
{
	t_tag	*head;
	t_tag	*current;

	while (*line != '\0')
	{
		line += 1;
	}
	return (head);
}

t_tag	*create_tree(char *line)
{
	t_tag	*head;
	int		number_of_operators;

	remove_insignificant_spases(&line);
	remove_insignificant_brackets(&line);
	number_of_operators = count_the_number_of_operators(line);
	printf("\x1b[32mResult:\x1b[0m %s\n", line);
	head = create_the_current_level(line);
	free(line);
	return (NULL);
}

t_tag	*parser(char *line)
{
	t_tag	*head;
	
	if (check_the_syntax(line) != 0)
		return (NULL);
	head = create_tree(line);
	return (head);
}
