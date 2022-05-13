/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_of_parentheses.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:17:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/13 23:43:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_this_an_operator(char **line)
{
	if (ft_strncmp(*line, "&&", 2) == 0)
	{
		*line += 2;
		return (AND);
	}
	else if (ft_strncmp(*line, "||", 2) == 0)
	{
		*line += 2;
		return (OR);
	}
	else if (**line == '|')
	{
		*line += 1;
		return (PIPE);
	}
	else if (**line == ';')	
	{
		*line += 1;
		return (SEQUENCE);
	}
	else
	{
		*line += 1;
		return (EMPTY);
	}
}

// static void	is_this_a_single_quotation_mark(char **line)
// {
// 	if (**line != '\'')
// 		return ;
// 	*line += 1;
// 	while (**line != '\'')
// 	{
// 		*line += 1;
// 	}
// 	*line += 1;
// }

// static void	is_this_a_double_quotation_mark(char **line)
// {
// 	if (**line != '\"')
// 		return ;
// 	*line += 1;
// 	while (**line != '\"')
// 	{
// 		*line += 1;
// 	}
// 	*line += 1;
// }

// static void	is_this_a_brace(char **line)
// {
// 	int	number_of_open_brackets;

// 	if (**line != '(')
// 		return ;
// 	*line += 1;
// 	number_of_open_brackets = 1;
// 	while (number_of_open_brackets != 0) 
// 	{
// 		if (**line == '(')
// 		{
// 			number_of_open_brackets += 1;
// 		}
// 		if (**line == ')')
// 		{
// 			number_of_open_brackets -= 1;
// 		}
// 		*line += 1;
// 	}
// }

int	check_syntax_of_parentheses(char *line)
{
	int	operator;
	int	was_operator;

	operator = EMPTY;
	while (*line != '\0')
	{
		was_operator = is_this_an_operator(&line);
		if (was_operator != EMPTY)
			operator = was_operator;
		if (*line == '(' && operator == EMPTY)
		{
			printf("minishell: syntax error near unexpected token '('\n");
			return (-1);
		}
	}
	return (0);
}
