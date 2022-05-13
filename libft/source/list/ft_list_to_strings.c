/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//		Converts a list to a string.
char	**ft_list_to_strings(t_list *head)
{
	char	**strings;
	int		i;

	strings = (char **)malloc(sizeof(char *) * (ft_list_count(head) + 1));
	if (strings == NULL)
		return (NULL);
	i = 0;
	while (head != LIST_END)
	{
		strings[i] = head->data;
		head = head->next;
		i += 1;
	}
	strings[i] = NULL;
	return (strings);
}
