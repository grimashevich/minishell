/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_container_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:31:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 04:35:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*func_join_all(char *line, char *left)
{
	char	*right;
	int		i;
	int		lenght;

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
	free(right);
	if (line == NULL)
	{
		perror("minishell");
		exit(1);
	}
	return (line);
}

char	*par_for_red(char *line)
{
	char	*left;
	char	*right;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '(')
		i += 1;
	left = ft_substr(line, 0, i);
	if (left == NULL)
	{
		perror("minishell");
		exit(1);
	}
	line = func_join_all(line, left);
	free(left);
	return (line);
}
