/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:44:12 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/27 13:40:41 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_(char *code)
{
	int	i;

	i = 0;
	if (code[i] == '-')
	{
		i += 1;
	}
	if (code[i] == '\0')
	{
		write(2, "exit\n", 5);
		write(2, "minishell: exit: -: numeric argument required\n", 46);
		exit(255);
	}
	while (ft_isdigit(code[i]) == TRUE)
	{
		i += 1;
	}
	if (code[i] != '\0')
	{
		write(2, "exit\n", 5);
		write(2, "minishell: exit: ", 17);
		write(2, code, ft_strlen(code));
		write(2, ": numeric argument required\n", 28);
		exit(255);
	}
}

void	built_exit(char **code)
{
	unsigned char	_code;

	if (code[1] == NULL)
	{
		write(2, "exit\n", 5);
		exit(0);
	}
	check_(code[1]);
	_code = ft_atoi(code[1]);
	if (code[2] != NULL)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return ;
	}
	write(2, "exit\n", 5);
	exit(_code);
}
