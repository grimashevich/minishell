/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_parentheses_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:17:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 03:18:22 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	skip_red_all(char **string, int *operator)
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
		while (ft_isalnum(**string) == TRUE || **string == '_')
			*string += 1;
		while (ft_isspace(**string) == TRUE)
			*string += 1;
	}
}

int	check_parentheses_all_t(char **string, int *operator)
{
	int	i;

	skip_red_all(string, operator);
	i = 0;
	while (ft_isdigit((*string)[i]) == TRUE)
		i += 1;
	if ((*string)[i] == '>' || (*string)[i] == '<')
	{
		*operator = is_this_operator(string);
		return (0);
	}
	if (ft_isalnum(**string) == TRUE)
	{
		write(2, "minishell: syntax error near unexpected token '", 47);
		write(2, *string, get_lenght(*string));
		write(2, "'\n", 2);
		return (-1);
	}
	*operator = is_this_operator(string);
	return (0);
}

int	check_parentheses_after_operator(char *string)
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
		if (*string == '\0' || (*string == ')' && *(string + 1) == '\0'))
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
