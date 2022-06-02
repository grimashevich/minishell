/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclown_func3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:47:17 by EClown            #+#    #+#             */
/*   Updated: 2022/06/01 21:04:24 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

static int	open_quotes2(char *str_char, char *cur_char)
{
	int	result;

	result = 0;
	if (*str_char == *cur_char)
		*cur_char = 0;
	else if (*cur_char == 0 && *str_char == '"')
		*cur_char = '"';
	else if (*cur_char == 0 && *str_char == '\'')
		*cur_char = '\'';
	else
		result = 1;
	return (result);
}

char	*open_quotes(char *str)
{
	char	cur_char;
	char	*result;
	int		i;

	if (str == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	cur_char = 0;
	while (*str)
	{
		if (open_quotes2(str, &cur_char))
			result[i++] = *str;
		str++;
	}
	result[i] = 0;
	return (result);
}

void	exit_if_null(void *pointer)
{
	if (pointer == NULL)
	{
		write(2, "minishell: malloc error\n", 24);
		exit(1);
	}
}
