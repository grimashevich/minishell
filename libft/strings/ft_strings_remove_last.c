/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_remove_last.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:05:56 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 23:18:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	remove_last(char **strings, char **new)
{
	size_t	i;

	i = 0;
	while (strings[i + 1] != NULL)
	{
		new[i] = strings[i];
		i += 1;
	}
	free(strings[i]);
	new[i] = NULL;
}

void	ft_strings_remove_last(char ***strings)
{
	char	**new;

	if (**strings == NULL)
		return ;
	new = (char **)malloc(ft_strings_count(*strings) * sizeof(char *));
	if (new == NULL)
	{
		ft_strings_remove_all(strings);
		return ;
	}
	remove_last(*strings, new);
	free(*strings);
	*strings = new;
}
