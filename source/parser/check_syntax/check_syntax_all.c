/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:10:34 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/24 18:21:58 by ccamie           ###   ########.fr       */
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
	if (right > 2)
	{
		if (right == 3)
			write(1, "minishell: syntax error near unexpected token '>'\n", 51);
		else if (right >= 4)
			write(1, "minishell: syntax error near unexpected token '>>'\n", 52);
		return (-1);
	}
	if (left != 0 && right == 0)
	{
		if (left <= 3)
			write(1, "minishell: syntax error near unexpected token 'newline'\n", 57);
		else if (left == 4)
			write(1, "minishell: syntax error near unexpected token '<'\n", 51);
		else if (left == 5)
			write(1, "minishell: syntax error near unexpected token '<<'\n", 52);
		else if (left >= 6)
			write(1, "minishell: syntax error near unexpected token '<<<'\n", 53);
		return (-1);
	}
	if (left == 1)
		write(1, "minishell: syntax error near unexpected token '<'\n", 51);
	else if (left == 2)
		write(1, "minishell: syntax error near unexpected token '<<'\n", 52);
	else if (left >= 3)
		write(1, "minishell: syntax error near unexpected token '<<<'\n", 53);
	if (right <= 2 && left == 0)
		write(1, "minishell: syntax error near unexpected token 'newline'\n", 57);
	return (-1);
}