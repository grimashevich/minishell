/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_of_redirect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:16:32 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/19 22:11:09 by ccamie           ###   ########.fr       */
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
		write(1, "minishell: syntax error near unexpected token '", 47);
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
		write(1, "minishell: syntax error near unexpected token '", 47);
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
		write(1, "minishell: syntax error near unexpected token 'newline'", 56);
		return (-1);
	}
	if (*(string + 1) == '>')
	{
		write(1, "minishell: syntax error near unexpected token '>>'", 51);
		return (-1);
	}
	else
	{
		// printf("minishell: syntax error near unexpected token '>'\n");
		write(1, "minishell: syntax error near unexpected token '>'", 50);
		return (-1);
	}
	return (0);
}

int	check_syntax_of_redirect_outfile(char *string)
{
	while (*string !='\0')
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
			if (ft_isalnum(*string) == FALSE)
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
		write(1, "minishell: syntax error near unexpected token 'newline'\n", 56);
		return (-1);
	}
	if (i == 4)
	{
		write(1, "minishell: syntax error near unexpected token '<'\n", 51);
		return (-1);
	}
	if (i == 5)
	{
		write(1, "minishell: syntax error near unexpected token '<<'\n", 52);
		return (-1);
	}
	if (i >= 6)
	{
		write(1, "minishell: syntax error near unexpected token '<<<'\n", 52);
		return (-1);
	}
	return (0);
}

int	check_syntax_of_redirect_infile(char *string)
{
	int	i;

	while (*string !='\0')
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
