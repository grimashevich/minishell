/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:00:14 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/06 17:12:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_this_an_operator(char *line, char *string)
{
	if (ft_strncmp(line, "&&", 2) == 0)
	{
	printf("\x1b[32mThe %s operator:\x1b[0m &&\n", string);
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", line);
	printf("+------------------------------------------------------------------------------+\n");
		return (AND);
	}
	else if (ft_strncmp(line, "||", 2) == 0)
	{
	printf("\x1b[32mThe %s operator:\x1b[0m ||\n", string);
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", line);
	printf("+------------------------------------------------------------------------------+\n");
		return (OR);
	}
	else if (*line == '|')
	{
	printf("\x1b[32mThe %s operator:\x1b[0m |\n", string);
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", line);
	printf("+------------------------------------------------------------------------------+\n");
		return (PIPE);
	}
	else if (*line == ';')	
	{
	printf("\x1b[32mThe %s operator:\x1b[0m ;\n", string);
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", line);
	printf("+------------------------------------------------------------------------------+\n");
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
			printf("\x1b[32mThe previous operator: \x1b[31mWas not found\x1b[0m\n");
			printf("+------------------------------------------------------------------------------+\n");
			printf("| %-77s|\n", line);
			printf("+------------------------------------------------------------------------------+\n");
			break ;
		}
		operator = is_this_an_operator(line, "previous");
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
			printf("\x1b[32mThe next operator was not found:\x1b[0m\n");
			printf("+------------------------------------------------------------------------------+\n");
			printf("| %-77s|\n", line);
			printf("+------------------------------------------------------------------------------+\n");
			break ;
		}
		operator = is_this_an_operator(line + i, "next");
		if (operator != EMPTY)
		{
			return (operator);
		}
		i += 1;
	}
	return (EMPTY);	
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
	commamd->command = (char **)malloc(2 * sizeof(char *));	// ban
	commamd->command[0] = ft_strdup(line);
	commamd->command[1] = NULL;
	return (commamd);
}
