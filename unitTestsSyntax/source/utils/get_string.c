/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:49:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 15:27:16 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unittest.h"

static size_t	number_of_characters_before_quotation_mark(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\"')
	{
		i += 1;
	}
	return (i);
}

static char	*_get_value_string(char *variable)
{
	size_t	lenght;
	char	*value;

	variable += number_of_characters_before_quotation_mark(variable) + 1;
	lenght = number_of_characters_before_quotation_mark(variable);
	value = strndup(variable, lenght);
	if (value == NULL)
	{
		exit(ERROR);
	}
	else
	{
		return (value);
	}
}

void	add_to_list_allocated(char *value)
{
	t_list	*element;

	element = ft_list_init(value);
	if (element == LIST_FAILED)
	{
		exit(ERROR);
	}
	else
	{
		ft_list_append(&g_local.allocated, element);
	}
}

char	*get_value_string(char *variable)
{
	char	find[128];
	char	*finded;
	char	*value;

	sprintf(find, ": %s :", variable);
	finded = strstr(g_local.test, find);
	finded += strlen(variable) + 4;
	value = _get_value_string(finded);
	if (strcmp(value, "NULL") == 0)
	{
		free(value);
		return (NULL);
	}
	else
	{
		add_to_list_allocated(value);
		return (value);
	}
}
