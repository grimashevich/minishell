/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_container.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:30:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/06 19:59:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tag	*create_the_current_level(char *line);
void	remove_insignificant_spases(char **line);
void	remove_insignificant_brackets(char **line);

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
		if (*line == '(')
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
		if (line[i] == ')')
		{
			printf("\x1b[32mThe next operator: \x1b[31mWas not found\x1b[0m\n");
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

char	*new_line(char *line)
{
	int	i;
	int	j;

	i = ft_strchr(line, '(') - line + 1;
	j = ft_strrchr(line, ')') - line ;
	printf("\x1b[33mStart:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77d|\n", i);
	printf("+------------------------------------------------------------------------------+\n");
	printf("\x1b[33mLenght:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77d|\n", j - i);
	printf("+------------------------------------------------------------------------------+\n");
	line = ft_substr(line, i, j - i);
	printf("\x1b[33mCreate line for tree:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", line);
	printf("+------------------------------------------------------------------------------+\n");
	if (line == NULL)
	{
		perror("minishell");
		exit(1);
	}
	return (line);
}

t_cont	*get_container(char *line)
{
	t_cont	*container;

	container = (t_cont *)malloc(sizeof(t_cont));
	if (container == NULL)
	{
		perror("minishell");
		exit(1);
	}
	container->prev_operator = get_prev_operator(line);
	container->next_operator = get_next_operator(line);
	line = new_line(line);
	remove_insignificant_spases(&line);
	remove_insignificant_brackets(&line);
	printf("\x1b[43m+------------------------------------------------------------------------------+\x1b[0m\n");
	printf("\x1b[43m|                                                                              |\x1b[0m\n");
	printf("\x1b[43m+------------------------------------------------------------------------------+\x1b[0m\n");
	printf("\x1b[32mResult:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", line);
	printf("+------------------------------------------------------------------------------+\n");
	container->tag = create_the_current_level(line);
	free(line);
	printf("\x1b[44m+------------------------------------------------------------------------------+\x1b[0m\n");
	printf("\x1b[44m|                                                                              |\x1b[0m\n");
	printf("\x1b[44m+------------------------------------------------------------------------------+\x1b[0m\n");
	return (container);
}
