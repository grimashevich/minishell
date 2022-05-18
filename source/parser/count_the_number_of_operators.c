/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_the_number_of_operators.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:17:27 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/18 18:55:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	is_this_an_operator(char **line, int *number_of_operators)
{
	if (ft_strncmp(*line, "&&", 2) == 0)
	{
	printf("\x1b[32mOperator found: && \x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line);
	printf("+------------------------------------------------------------------------------+\n");
		*line += 2;
	}
	else if (ft_strncmp(*line, "||", 2) == 0)
	{
	printf("\x1b[32mOperator found: || \x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line);
	printf("+------------------------------------------------------------------------------+\n");
		*line += 2;
	}
	else if (**line == '|')	
	{
	printf("\x1b[32mOperator found: | \x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line);
	printf("+------------------------------------------------------------------------------+\n");
		*line += 1;
	}
	else if (**line == ';')	
	{
	printf("\x1b[32mOperator found: ; \x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line);
	printf("+------------------------------------------------------------------------------+\n");
		*line += 1;
	}
	else
	{
		*line += 1;
		return ;
	}
	*number_of_operators += 1;
}

static void	is_this_a_brace(char **line)
{
	int	number_of_open_brackets;

	if (**line != '(')
		return ;
	*line += 1;
	printf("\x1b[33mThe opening bracket is found:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line - 1);
	printf("+------------------------------------------------------------------------------+\n");
	number_of_open_brackets = 1;
	while (number_of_open_brackets != 0) 
	{
		if (**line == '(')
		{
	printf("\x1b[33mThe opening bracket is found:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line - 1);
	printf("+------------------------------------------------------------------------------+\n");
			number_of_open_brackets += 1;
		}
		if (**line == ')')
		{
	printf("\x1b[33mThe closing bracket is found:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line);
	printf("+------------------------------------------------------------------------------+\n");
			number_of_open_brackets -= 1;
		}
		*line += 1;
	}
}

static void	is_this_a_single_quotation_mark(char **line)
{
	if (**line != '\'')
		return ;
	*line += 1;
	printf("\x1b[33mThe opening single quotation mark is found:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line - 1);
	printf("+------------------------------------------------------------------------------+\n");
	while (**line != '\'')
	{
		*line += 1;
	}
	*line += 1;
	printf("\x1b[33mThe closing single quotation mark is found:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line - 1);
	printf("+------------------------------------------------------------------------------+\n");
}

static void	is_this_a_double_quotation_mark(char **line)
{
	if (**line != '\"')
		return ;
	*line += 1;
	printf("\x1b[33mThe opening double quotation mark is found:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line - 1);
	printf("+------------------------------------------------------------------------------+\n");
	while (**line != '\"')
	{
		*line += 1;
	}
	*line += 1;
	printf("\x1b[33mThe opening double quotation mark is found:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", *line - 1);
	printf("+------------------------------------------------------------------------------+\n");
}

int	count_the_number_of_operators(char *line)
{
	int	number_of_operators;

	number_of_operators = 0;
	while (*line != '\0')
	{
		is_this_a_single_quotation_mark(&line);
		is_this_a_double_quotation_mark(&line);
		is_this_a_brace(&line);
		is_this_an_operator(&line, &number_of_operators);
	}
	printf("\x1b[33mNumber of operators:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77d|\n", number_of_operators);
	printf("+------------------------------------------------------------------------------+\n");
	return (number_of_operators);
}
