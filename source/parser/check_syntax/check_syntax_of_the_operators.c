/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_of_the_operators.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:16:35 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/13 23:21:21 by ccamie           ###   ########.fr       */
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

void	print_error_syntax_of_the_operators(int operator)
{
	if (operator == AND)
		printf("minishell: syntax error near unexpected token '&&'\n");
	else if (operator == OR)
		printf("minishell: syntax error near unexpected token '||'\n");
	else if (operator == PIPE)
		printf("minishell: syntax error near unexpected token '|'\n");
	else if (operator == SEQUENCE)
		printf("minishell: syntax error near unexpected token ';'\n");
}

static void	is_this_a_brace(char **line, int *operator)
{
	int	number_of_open_brackets;

	if (**line != '(')
		return ;
	*operator = EMPTY;
	*line += 1;
	number_of_open_brackets = 1;
	while (number_of_open_brackets != 0) 
	{
		if (**line == '(')
		{
			number_of_open_brackets += 1;
		}
		if (**line == ')')
		{
			number_of_open_brackets -= 1;
		}
		*line += 1;
	}
}

static void	is_this_a_single_quotation_mark(char **line)
{
	int	j;

	if (**line != '\'')
		return ;
	j = 1;
	while ((*line)[j] != '\'' && (*line)[j] != '\0')
	{
		j += 1;
	}
	j += 1;
	*line += j;
}

static void	is_this_a_double_quotation_mark(char **line)
{
	int	j;

	if (**line != '\"')
		return ;
	j = 1;
	while ((*line)[j] != '\"' && (*line)[j] != '\0')
	{
		j += 1;
	}
	j += 1;
	*line += j;
}

int	check_syntax_of_the_operators(char *line)
{
	int	was_there_an_operator_there;
	int	was_operator;
	int	operator;

	was_there_an_operator_there = FALSE;
	operator = EMPTY;
	while (*line != '\0')
	{
		is_this_a_single_quotation_mark(&line);
		is_this_a_double_quotation_mark(&line);
		was_operator = is_this_an_operator(&line);
		if (was_operator != EMPTY)
			operator = was_operator;
		if (operator != EMPTY && was_there_an_operator_there == TRUE)
			break ;
		if (operator != EMPTY)
			was_there_an_operator_there = TRUE;
		is_this_a_brace(&line, &operator);
		if (ft_isalnum(*line) == TRUE)
			was_there_an_operator_there = FALSE;
	}
	if (was_there_an_operator_there == TRUE)
	{
		print_error_syntax_of_the_operators(operator);
		return (-1);
	}
	return (0);
}
