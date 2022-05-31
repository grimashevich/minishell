/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:10:34 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 03:40:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_syntax_costil_nbr2(char *string)
{
	int	i;

	if (*string != '\"')
	{
		return (0);
	}
	i = 0;
	while (string[i + 1] != '\0')
	{
		i += 1;
	}
	if (string[i] == '\"')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	print_itisnot_right(int right, int left)
{
	if (right == 3)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '>'\n", 40);
	}
	else if (right >= 4)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '>>'\n", 41);
	}
}

void	print_itisnot_left(int right, int left)
{
	if (left <= 3)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token 'newline'\n", 46);
	}
	else if (left == 4)
		write(2, "minishell: syntax error near unexpected token '<'\n", 51);
	else if (left == 5)
		write(2, "minishell: syntax error near unexpected token '<<'\n", 52);
	else if (left >= 6)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token '<<<'\n", 42);
	}
}

void	print_itisnot_ok(int right, int left)
{
	if (right > 2)
	{
		print_itisnot_right(right, left);
		return ;
	}
	if (left != 0 && right == 0)
	{
		print_itisnot_left(right, left);
		return ;
	}
	if (left == 1)
		write(2, "minishell: syntax error near unexpected token '<'\n", 51);
	else if (left == 2)
		write(2, "minishell: syntax error near unexpected token '<<'\n", 52);
	else if (left >= 3)
		write(2, "minishell: syntax error near unexpected token '<<<'\n", 53);
	if (right <= 2 && left == 0)
	{
		write(2, "minishell: ", 11);
		write(2, "syntax error near unexpected token 'newline'\n", 46);
	}
}

int	check_syntax_costil_nbr1(char *string)
{
	int	i;
	int	right;
	int	left;

	i = 0;
	while (string[i] != '\0' && ft_strchr("< \t>", string[i]) != NULL)
		i += 1;
	if (string[i] != '\0')
		return (0);
	right = 0;
	left = 0;
	while (string[right] == '>')
		right += 1;
	i = right;
	while (string[i + left] == '<')
		left += 1;
	print_itisnot_ok(right, left);
	return (-1);
}
