/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/30 13:49:39 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_quotation_mark_syntax(char *line);
int	check_syntax_of_parentheses(char *line);
int	check_syntax_of_operators(char *line);
int	check_syntax_of_redirect(char *line);
int	check_syntax_costil_nbr2(char *string);
int	check_syntax_costil_nbr1(char *string);

int	check_syntax(char *string)
{
	if (check_syntax_costil_nbr1(string) != 0)
	{
		g_ms.exit_code = 258;
		return (-1);
	}
	if (check_quotation_mark_syntax(string) != 0)
	{
		g_ms.exit_code = 258;
		return (-1);
	}
	if (check_syntax_costil_nbr2(string) == 1)
	{
		g_ms.exit_code = 258;
		return (0);
	}
	if (check_syntax_of_parentheses(string) != 0)
	{
		g_ms.exit_code = 258;
		return (-1);
	}
	if (check_syntax_of_operators(string) != 0)
	{
		g_ms.exit_code = 258;
		return (-1);
	}
	if (check_syntax_of_redirect(string) != 0)
	{
		g_ms.exit_code = 258;
		return (-1);
	}
	return (0);
}
