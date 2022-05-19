/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_of_operators.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:16:35 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/19 22:14:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_error(int operator)
{
	if (operator == AND)
	{
		write(1, "minishell: syntax error near unexpected token '&&'\n", 51);
	}
	else if (operator == OR)
	{
		write(1, "minishell: syntax error near unexpected token '||'\n", 51);
	}
	else if (operator == PIPE)
	{
		write(1, "minishell: syntax error near unexpected token '|'\n", 50);
	}
	else if (operator == SEQUENCE)
	{
		write(1, "minishell: syntax error near unexpected token ';'\n", 50);
	}
}

int	skip_all_quotation_mar_operator(char **string)
{
	if (**string == '\'')
	{
		*string += skip_single_quotation_mark(*string + 1) + 1;
		if (*(*string + 1) == '\0')
			return (1);
	}
	if (**string == '\"')
	{
		*string += skip_double_quotation_mark(*string + 1) + 1;
		if (*(*string + 1) == '\0')
			return (1);
	}
	return (0);
}

int	check_all_operators(char **string, 	int	*iscommand, int *operator, int *was_operator)
{
	if (ft_isalnum(**string) == TRUE)
		*iscommand = TRUE;
	*operator = is_this_operator(string);
	if (*operator != EMPTY)
	{
		if (*iscommand == FALSE)
		{
			print_error(*operator);
			return (-1);
		}
		else
		{
			*was_operator = *operator;
			*iscommand = FALSE;
		}
	}
	return (0);
}

int	check_syntax_of_operators(char *string)
{
	int	iscommand;
	int	operator;
	int	was_operator;

	iscommand = FALSE;
	operator = EMPTY;
	was_operator = EMPTY;
	while (*string != '\0')
	{
		if (skip_all_quotation_mar_operator(&string) == 1)
			return (0);
		if (check_all_operators(&string, &iscommand, &operator, &was_operator) == -1)
			return (-1);
	}
	if (operator != EMPTY || iscommand == FALSE)
	{
		print_error(was_operator);
		return (-1);
	}
	return (0);
}
