/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_a_line_before_operator.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:17:33 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/19 21:42:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_this_an_operator(char *line, int *j)
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

static void	is_this_a_brace(char *line, int *i)
{
	int	number_of_open_brackets;
	int	j;

	if (*line != '(')
		return ;
	j = 1;
	number_of_open_brackets = 1;
	while (number_of_open_brackets != 0) 
	{
		if (line[j] == '(')
		{
			number_of_open_brackets += 1;
		}
		if (line[j] == ')')
		{
			number_of_open_brackets -= 1;
		}
		j += 1;
	}
	*i += j;
}

static void	is_this_a_single_quotation_mark(char *line, int *i)
{
	int	j;

	if (*line != '\'')
		return ;
	j = 1;
	while (line[j] != '\'')
	{
		j += 1;
	}
	j += 1;
	*i += j;
}

static void	is_this_a_double_quotation_mark(char *line, int *i)
{
	int	j;

	if (*line != '\"')
		return ;
	j = 1;
	while (line[j] != '\"')
	{
		j += 1;
	}
	j += 1;
	*i += j;
}

char	*give_a_line_before_operator(char **line, int *prev_op_int)
{
	char	*temporary;
	int		i;
	int		j;

	temporary = *line;
	i = 0;
	j = 0;
	while (temporary[i] != '\0')
	{
		is_this_a_double_quotation_mark(temporary + i, &i);
		is_this_a_single_quotation_mark(temporary + i, &i);
		is_this_a_brace(temporary + i, &i);
		if (is_this_an_operator(temporary + i, &j) == TRUE)
		{
			temporary = ft_substr(temporary - *prev_op_int, 0, i + *prev_op_int + j);
			if (temporary == NULL)
			{
				perror("minishell");
				exit(1);
			}
			i += j;
			*line += i;
			*prev_op_int = j;
			return (temporary);
		}
		else
		{
			if (temporary[i] == '\0')
			{
				break ;
			}
			i += 1;
		}
	}
	temporary = ft_substr(temporary - *prev_op_int, 0, i + *prev_op_int);
	if (temporary == NULL)
	{
		perror("minishell");
		exit(1);
	}
	*line += i;
	return (temporary);
}
