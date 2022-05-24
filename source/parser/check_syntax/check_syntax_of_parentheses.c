/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_of_parentheses.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:17:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/24 12:02:27 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_this_operator(char **string)
{
	if (**string == '&' && *(*string + 1) == '&')
	{
		*string += 2;
		return (AND);
	}
	else if (**string == '|' && *(*string + 1) == '|')
	{
		*string += 2;
		return (OR);
	}
	else if (**string == '|')
	{
		*string += 1;
		return (PIPE);
	}
	else if (**string == ';')	
	{
		*string += 1;
		return (SEQUENCE);
	}
	else
	{
		*string += 1;
		return (EMPTY);
	}
}

static int	check_open_close_parentheses(int number_of_open_parenthesis)
{
	if (number_of_open_parenthesis > 0)
	{
		write(1, "minishell: syntax error near unexpected token '('\n", 51);
		return (-1);
	}
	if (number_of_open_parenthesis < 0)
	{
		write(1, "minishell: syntax error near unexpected token ')'\n", 51);
		return (-1);
	}
	return (0);
}

static int	check_open_and_close(char *string)
{
	int	number_of_open_parenthesis;

	number_of_open_parenthesis = 0;
	while (*string != '\0')
	{
		if (*string == '\'')
			string += skip_single_quotation_mark(string + 1) + 1;
		if (*string == '\"')
			string += skip_double_quotation_mark(string + 1) + 1;
		if (*string == '(')
			number_of_open_parenthesis += 1;
		else if (*string == ')')
			number_of_open_parenthesis -= 1;
		string += 1;
	}
	if (check_open_close_parentheses(number_of_open_parenthesis) == -1)
		return (-1);
	return (0);
}

static int	check_parentheses_befor_operator(char *string)
{
	int	iscommand;
	int	operator;

	iscommand = FALSE;
	operator = EMPTY;
	while (*string != '\0')
	{
		if (*string == '\'')
			string += skip_single_quotation_mark(string + 1) + 1;
		if (*string == '\"')
			string += skip_double_quotation_mark(string + 1) + 1;
		if (ft_isalnum(*string) == TRUE)
			iscommand = TRUE;
		if (*string == '(' && iscommand == TRUE)
		{
			write(1, "minishell: syntax error near unexpected token '('\n", 51);
			return (-1);
		}
		operator = is_this_operator(&string);
		if (operator != EMPTY)
			iscommand = FALSE;
	}
	return (0);
}

static int	get_lenght(char *string)
{
	int	i;

	i = 0;
	while (ft_isalnum(string[i]) == TRUE)
	{
		i += 1;
	}
	return (i);
}

static int	check_parentheses_all_t(char **string, int *operator)
{
	if (**string == '\'')
		*string += skip_single_quotation_mark(*string + 1) + 1;
	if (**string == '\"')
		*string += skip_double_quotation_mark(*string + 1) + 1;
	while (**string == '>' || **string == '<')
	{
		*string += 1;
		while (ft_isspace(**string) == TRUE)
			*string += 1;
		while (ft_isalnum(**string) == TRUE)
			*string += 1;
		while (ft_isspace(**string) == TRUE)
			*string += 1;
	}
	if (ft_isalnum(**string) == TRUE)
	{
		write(1, "minishell: syntax error near unexpected token '", 47);
		write(1, *string, get_lenght(*string));
		write(1, "''", 1);
		return (-1);
	}
	*operator = is_this_operator(string);
	return (0);
}

static int	check_parentheses_after_operator(char *string)
{
	int	operator;

	operator = EMPTY;
	while (*string != '\0')
	{
		while (*string != ')' && *string != '\0')
		{
			if (*string == '\'')
				string += skip_single_quotation_mark(string + 1) + 1;
			if (*string == '\"')
				string += skip_double_quotation_mark(string + 1) + 1;
			string += 1;
		}
		if (*string == '\0')
			return (0);
		while (operator == EMPTY && *string != '\0')
		{
			if (check_parentheses_all_t(&string, &operator) == -1)
			{
				return (-1);
			}
		}
	}
	return (0);
}

int	check_syntax_of_parentheses(char *string)
{
	if (check_open_and_close(string) != 0)
	{
		return (-1);
	}
	if (check_parentheses_befor_operator(string) != 0)
	{
		return (-1);
	}
	if (check_parentheses_after_operator(string) != 0)
	{
		return (-1);
	}
	return (0);
}

