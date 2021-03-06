/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_container.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:30:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/24 21:45:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tag	*create_the_current_level(char *line);
void	remove_insignificant_spases(char **line);
void	remove_insignificant_brackets(char **line);

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
		if (*line == '(')
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
		if (line[i] == ')')
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

char	*new_line(char *line)
{
	int	i;
	int	j;

	i = ft_strchr(line, '(') - line + 1;
	j = ft_strrchr(line, ')') - line ;
	line = ft_substr(line, i, j - i);
	if (line == NULL)
	{
		perror("minishell");
		exit(1);
	}
	return (line);
}

t_rdr_fls	*extract_all_rdrs(char **str);
char		*ft_strjoin3(char *str1, char *str2, char *str3);

char	*par_for_red(char *line)
{
	char	*left;
	char	*right;
	int		i;
	int		lenght;

	i = 0;
	while (line[i] != '\0' && line[i] != '(')
		i += 1;
	left = ft_substr(line, 0, i);
	if (left == NULL)
	{
		perror("minishell");
		exit(1);
	}
	lenght = ft_strlen(line);
	i = lenght;
	while (i > 0 && line[i] != ')')
		i -= 1;
	right = ft_substr(line, i + 1, lenght - i - 1);
	if (right == NULL)
	{
		perror("minishell");
		exit(1);
	}
	line = ft_strjoin3(left, " ", right);
	if (line == NULL)
	{
		perror("minishell");
		exit(1);
	}
	free(left);
	free(right);
	return (line);
}
// echo 1 && (echo 2 || echo 3) > file
t_cont	*get_container(char *line)
{
	t_cont	*container;
	char	*string;

	container = (t_cont *)malloc(sizeof(t_cont));
	if (container == NULL)
	{
		perror("minishell");
		exit(1);
	}
	container->prev_operator = get_prev_operator(line);
	container->next_operator = get_next_operator(line);
	string = par_for_red(line);
	container->redirects = extract_all_rdrs(&string);
	free(string);
	line = new_line(line);
	remove_insignificant_spases(&line);
	remove_insignificant_brackets(&line);
	container->tag = create_the_current_level(line);
	free(line);
	return (container);
}
