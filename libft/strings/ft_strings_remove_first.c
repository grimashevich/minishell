/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_remove_first.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:06:00 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 23:18:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	remove_first(char **strings, char **new)
{
	size_t	i;

	free(*strings++);
	i = 0;
	while (strings[i] != NULL)
	{
		new[i] = strings[i];
		i += 1;
	}
	new[i] = NULL;
}

void	ft_strings_remove_first(char ***strings)
{
	char	**new;

	new = (char **)malloc(ft_strings_count(*strings) * sizeof(char *));
	if (new == NULL)
	{
		ft_strings_remove_all(strings);
		return ;
	}
	remove_first(*strings, new);
	free(*strings);
	*strings = new;
}
