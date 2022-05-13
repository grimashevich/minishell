/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotation_mark_syntax.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:17:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/13 22:19:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_a_single_quotation_mark(char *line)
{
	int	number_of_single_quotation_mark;

	number_of_single_quotation_mark = 0;
	while (*line !='\0')
	{
		if (*line == '\'')
			number_of_single_quotation_mark += 1;
		line += 1;
	}
	if (number_of_single_quotation_mark % 2 == 0)
		return (0);
	else
		return (-1);
}

int	check_a_double_quotation_mark(char *line)
{
	int	number_of_double_quotation_mark;

	number_of_double_quotation_mark = 0;
	while (*line !='\0')
	{
		if (*line == '\"')
			number_of_double_quotation_mark += 1;
		line += 1;
	}
	if (number_of_double_quotation_mark % 2 == 0)
		return (0);
	else
		return (-1);
}

int	check_quotation_mark_syntax(char *line)
{
	if (check_a_single_quotation_mark(line) != 0)
	{
		printf("bash: syntax error near unexpected token '\''\n");
		return (-1);
	}
	if (check_a_double_quotation_mark(line) != 0)
	{
		printf("bash: syntax error near unexpected token '\"'\n");
		return (-1);
	}
	return (0);
}
