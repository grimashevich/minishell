/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 20:09:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"
#include <stdlib.h>

char	**ft_list_to_strings(t_list *list)
{
	char	**strings;
	int		i;

	strings = (char **)malloc(sizeof(char *) * (ft_list_count(list) + 1));
	if (strings == NULL)
		return (NULL);
	i = 0;
	while (list != NULL)
	{
		strings[i] = list->data;
		list = list->next;
		i += 1;
	}
	strings[i] = NULL;
	return (strings);
}
