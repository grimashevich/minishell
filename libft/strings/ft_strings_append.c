/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:04:01 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 21:11:36 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static void	append(char **strings, char **new, char *string)
{
	size_t	i;

	i = 0;
	while (strings[i] != NULL)
	{
		new[i] = strings[i];
		i += 1;
	}
	new[i] = string;
	new[i + 1] = NULL;
}

void	ft_strings_append(char ***strings, char *string)
{
	char	**new;

	new = (char **)malloc((ft_strings_count(*strings) + 2) * sizeof(char *));
	if (new == NULL)
	{
		ft_strings_remove_all(strings);
		return ;
	}
	append(*strings, new, string);
	free(*strings);
	*strings = new;
}
