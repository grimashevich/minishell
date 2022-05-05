/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:28:46 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 19:44:41 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	remove(char **strings, char **new, int index)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		if (i == index)
		{
			free(strings[i]);
			strings++;
			if (strings[i] == NULL)
				break ;
		}
		new[i] = strings[i];
		i += 1;
	}
	new[i] = NULL;
}

void	ft_strings_remove(char ***strings, int index)
{
	char	**new;
	size_t	count;

	count = ft_strings_count(*strings);
	if (index < 0 || index >= (int)count)
		return ;
	new = (char **)malloc(count * sizeof(char *));
	if (new == NULL)
	{
		ft_strings_remove_all(strings);
		return ;
	}
	remove(*strings, new, index);
	free(*strings);
	*strings = new;
}
