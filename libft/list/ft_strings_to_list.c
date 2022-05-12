/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:10:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:10:44 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"

t_list	*ft_strings_to_list(char **strings)
{
	t_list	*list;
	t_list	*one;

	list = NULL;
	while (*strings != NULL)
	{
		one = ft_list_new(*strings);
		if (one == NULL)
		{
			ft_list_remove(one, NULL);
			ft_list_remove_all(&list, NULL);
			return (NULL);
		}
		ft_list_add_back(&list, one);
		strings++;
	}
	return (list);
}
