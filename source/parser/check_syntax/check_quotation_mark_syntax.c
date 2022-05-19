/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotation_mark_syntax.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:17:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/19 19:56:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	skip_single_quotation_mark(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\'' && string[i] != '\0')
	{
		i += 1;
	}
	return (i);
}

int	skip_double_quotation_mark(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\"' && string[i] != '\0')
	{
		i += 1;
	}
	return (i);
}

int	check_single_quotation_mark(char *string)
{
	while (*string != '\0')
	{
		if (*string == '\"')
		{
			string += 1;
			string += skip_double_quotation_mark(string);
			if (*string == '\0' && *(string + 1) == '\0')
				return (0);
		}
		if (*string == '\'')
		{
			string += 1;

			string += skip_single_quotation_mark(string);
			if (*string == '\0' && *(string + 1) == '\0')
				return (-1);
		}
		string += 1;
	}
	return (0);
}

int	check_double_quotation_mark(char *string)
{
	while (*string != '\0')
	{
		if (*string == '\"')
		{
			string += 1;
			string += skip_double_quotation_mark(string);
			if (*string == '\0' && *(string + 1) == '\0')
				return (-1);
		}
		if (*string == '\'')
		{
			string += 1;
			string += skip_single_quotation_mark(string);
			if (*string == '\0' && *(string + 1) == '\0')
			{
				return (0);
			}
		}
		string += 1;
	}
	return (0);
}

int	check_quotation_mark_syntax(char *string)
{
	if (check_single_quotation_mark(string) != 0)
	{
		// printf("minishell: syntax error near unexpected token '\''\n");
		write(1, "minishell: syntax error near unexpected token '\''", 49);	// '\n'
		return (-1);
	}
	if (check_double_quotation_mark(string) != 0)
	{
		// printf("minishell: syntax error near unexpected token '\"'\n");
		write(1, "minishell: syntax error near unexpected token '\"'", 49); // '\n'
		return (-1);
	}
	return (0);
}
