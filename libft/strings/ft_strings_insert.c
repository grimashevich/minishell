/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:01 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 18:24:45 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	insert(char **strings, char **new, char *string, int index)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		if (i == index)
		{
			new[i] = string;
			i += 1;
			strings--;
		}
		new[i] = strings[i];
		i += 1;
	}
	if (i <= index)
	{
		new[i] = string;
		i += 1;
	}
	new[i] = NULL;
}

void	ft_strings_insert(char ***strings, char *string, int index)
{
	char	**new;

	new = (char **)malloc((ft_strings_count(*strings) + 2) * sizeof(char *));
	if (new == NULL)
	{
		ft_strings_remove_all(strings);
		return ;
	}
	insert(*strings, new, string, index);
	free(*strings);
	*strings = new;
}
