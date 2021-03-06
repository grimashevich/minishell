/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:00:14 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/24 12:21:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void lvl2_parsing(char *cmd_str, t_cmd *cmd_struct);

static int	is_this_an_operator(char *line)
{
	if (ft_strncmp(line, "&&", 2) == 0)
	{
		return (AND);
	}
	else if (ft_strncmp(line, "||", 2) == 0)
	{
		return (OR);
	}
	else if (*line == '|')
	{
		return (PIPE);
	}
	else if (*line == ';')	
	{
		return (SEQUENCE);
	}
	else
	{
		return (EMPTY);
	}
}

static int	get_prev_operator(char *line)
{
	int	operator;

	while (*line != '\0')
	{
		if (ft_isalnum(*line) == TRUE)
		{
			break ;
		}
		operator = is_this_an_operator(line);
		if (operator != EMPTY)
		{
			return (operator);
		}
		line += 1;
	}
	return (EMPTY);	
}

static int	get_next_operator(char *line)
{
	int	operator;
	int	i;

	i = ft_strlen(line) - 1;
	while (i > 0 && ft_isspace(line[i]) == TRUE)
		i -= 1;
	i -= 1;
	while (i > 0 && line[i] != '\0')
	{
		if (ft_isalnum(line[i]) == TRUE)
		{
			break ;
		}
		operator = is_this_an_operator(line + i);
		if (operator != EMPTY)
		{
			return (operator);
		}
		i += 1;
	}
	return (EMPTY);	
}

char	*new_line_after_operator(char *line, t_cmd *commamd)
{
	char	*new;
	int		start;
	int		end;

	start = 0;
	if (commamd->prev_operator != EMPTY)
	{
		if (commamd->prev_operator == AND || commamd->prev_operator == OR)
			start = 2;
		else
			start = 1;
	}
	end = 0;
	if (commamd->next_operator != EMPTY)
	{
		if (commamd->next_operator == AND || commamd->next_operator == OR)
			end = 2;
		else
			end = 1;
	}
	new = ft_substr(line, start, ft_strlen(line) - end - start);
	if (new == NULL)
	{
		perror("minishell");
		exit(1);
	}
	remove_insignificant_spases(&new);
	return (new);
}

t_cmd	*get_command(char *line)
{
	t_cmd	*commamd;

	commamd = (t_cmd *)malloc(sizeof(t_cmd));
	if (commamd == NULL)
	{
		perror("minishell");
		exit(1);
	}
	commamd->prev_operator = get_prev_operator(line);
	commamd->next_operator = get_next_operator(line);
	line = new_line_after_operator(line, commamd);
	lvl2_parsing(line, commamd);
	free(line);
	return (commamd);
}
