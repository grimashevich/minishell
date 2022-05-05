/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/04 15:47:19 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_the_syntax_of_parentheses(char *line)
{
	// int	number_of_parentheses;

	// number_of_parentheses = 0;
	// while (*line != '\0')
	// {
	// 	if (*line == '(')
	// 		number_of_parentheses += 1;
	// 	if (*line == ')')
	// 		number_of_parentheses -= 1;
	// 	line += 1;
	// }
	// if (number_of_parentheses > 0)
	// {
	// 	printf("minishell: syntax error near unexpected token '('\n");
	// 	return (-1);
	// }
	// else if (number_of_parentheses < 0)
	// {
	// 	printf("minishell: syntax error near unexpected token ')'\n");
	// 	return (-1);
	// }
	// else
	// {
	// 	return (0);
	// }

	return (0);
}

int	check_the_syntax_of_the_operators(char *line)
{
	// int	number_of_commands;
	// int	number_of_operators;

	// number_of_commands = 0;
	// number_of_operators = 0;
	// while (*line != '\0')
	// {

		
	// 	line += 1;
	// }
	return (0);
}

int	check_the_quotation_mark_syntax(char *line)
{
	// check the quotation mark syntax
	// in case of an error, prints it
	return (0);
}

int	check_the_syntax(char *line)
{
	if (check_the_syntax_of_parentheses(line) != 0)
		return (-1);
	if (check_the_syntax_of_the_operators(line) != 0)
		return (-1);
	if (check_the_quotation_mark_syntax(line) != 0)
		return (-1);
	return (0);
}
