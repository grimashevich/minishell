/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_redirect_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:13:51 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/03 01:39:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_syntax_of_redirect_outfile(char *string)
{
	while (*string != '\0')
	{
		if (*string == '>')
		{
			string += 1;
			if (*string == '>')
				string += 1;
			while (ft_isspace(*string) == TRUE)
				string += 1;
			if (check_fd_redirect_outfile(string) == TRUE)
				return (-1);
			if (ft_isalnum(*string) == FALSE && *string != '\"' && \
				*string != '*' && *string != '?' && *string != '/')
			{
				if (print_error_redirect_outfile(string) == -1)
					return (-1);
			}
		}
		string += 1;
	}
	return (0);
}

int	check_error_infile(char *string, int i)
{
	if (check_newline(string + i) == TRUE)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token 'newline'\n", 45);
		return (-1);
	}
	if (i == 4)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '<'\n", 40);
		return (-1);
	}
	if (i == 5)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '<<'\n", 41);
		return (-1);
	}
	if (i >= 6)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '<<<'\n", 41);
		return (-1);
	}
	return (0);
}

int	check_syntax_of_redirect_infile(char *string)
{
	int	i;

	while (*string != '\0')
	{
		if (*string == '<')
		{
			i = 0;
			while (string[i] == '<')
				i += 1;
			if (check_fd_redirect_infile(string + i) == TRUE)
				return (-1);
			if (check_error_infile(string, i) == -1)
				return (-1);
			string += i;
		}
		string += 1;
	}
	return (0);
}
