/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_of_redirect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:16:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 03:22:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_newline(char *string)
{
	while (ft_isspace(*string) == TRUE)
	{
		string += 1;
	}
	if (*string == '\0')
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	check_fd_redirect_outfile(char *string)
{
	char	*num;
	int		i;

	while (ft_isspace(*string) == TRUE)
		string += 1;
	num = string;
	i = 0;
	while (ft_isdigit(*string) == TRUE)
	{
		string += 1;
		i += 1;
	}
	if (*string == '>' && i != 0)
	{
		write(2, "minishell: syntax error near unexpected token '", 47);
		write(1, num, i);
		write(1, "'\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	check_fd_redirect_infile(char *string)
{
	char	*num;
	int		i;

	while (ft_isspace(*string) == TRUE)
		string += 1;
	num = string;
	i = 0;
	while (ft_isdigit(*string) == TRUE)
	{
		string += 1;
		i += 1;
	}
	if (*string == '>' && i != 0)
	{
		write(2, "minishell: syntax error near unexpected token '", 47);
		if (ft_atol(num) > 2147483647)
			write(1, "-1\n", 3);
		else
			write(1, num, i);
		write(1, "'\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	print_error_redirect_outfile(char *string)
{
	if (check_newline(string) == TRUE)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token 'newline'\n", 46);
		return (-1);
	}
	if (*(string + 1) == '>')
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '>>'\n", 41);
		return (-1);
	}
	else
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '>'\n", 40);
		return (-1);
	}
	return (0);
}

int	check_syntax_of_redirect(char *string)
{
	if (check_syntax_of_redirect_infile(string) != 0)
	{
		return (-1);
	}
	if (check_syntax_of_redirect_outfile(string) != 0)
	{
		return (-1);
	}
	return (0);
}
