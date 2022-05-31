/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_a_line_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:52:08 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 04:53:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_this_an_operator(char *line, int *j)
{
	if (ft_strncmp(line, "&&", 2) == 0)
	{
		*j = 2;
		return (TRUE);
	}
	else if (ft_strncmp(line, "||", 2) == 0)
	{
		*j = 2;
		return (TRUE);
	}
	else if (*line == '|')
	{
		*j = 1;
		return (TRUE);
	}
	else if (*line == ';')
	{
		*j = 1;
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	cool_func(char **temporary, char **line, int *i, int *prev_op_int)
{
	int	j;

	j = 0;
	if (is_this_an_operator(*temporary + *i, &j) == TRUE)
	{
		*temporary = ft_substr(*temporary - *prev_op_int, 0, \
			*i + *prev_op_int + j);
		if (*temporary == NULL)
		{
			perror("minishell");
			exit(1);
		}
		*i += j;
		*line += *i;
		*prev_op_int = j;
		return (1);
	}
	else
	{
		if ((*temporary)[*i] == '\0')
			return (-1);
		*i += 1;
	}
	return (0);
}
