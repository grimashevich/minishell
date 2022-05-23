/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:50:18 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/10 19:05:00 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static size_t	get_lenght(char *value)
{
	size_t	i;

	i = 0;
	while (value[i] != ':' && value[i] != '\0')
	{
		i += 1;
	}
	return (i);
}

char	*get_value(char *variable)
{
	char	infix[1024];
	char	*value;

	sprintf(infix, ":%s:", variable);
	value = strstr(g_input, infix) + strlen(variable) + 2;
	value = strndup(value, get_lenght(value));
	if (value == NULL)
		exit(TEST_ERROR);
	if (strcmp(value, "NULL") == 0)
	{
		free(value);
		return (NULL);
	}
	else
	{
		return (value);
	}
}
