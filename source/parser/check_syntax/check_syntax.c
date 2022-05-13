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

#include "parser.h"

int	check_the_quotation_mark_syntax(char *line);
int	check_the_syntax_of_parentheses(char *line);
int	check_the_syntax_of_the_operators(char *line);

int	check_the_syntax(char *line)
{
	if (check_the_quotation_mark_syntax(line) != 0)
		return (-1);
	if (check_the_syntax_of_parentheses(line) != 0)
		return (-1);
	if (check_the_syntax_of_the_operators(line) != 0)
		return (-1);
	return (0);
}
