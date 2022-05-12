/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:31 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 20:00:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"

t_list	*ft_list_map(t_list *list, void *(*fun)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new;
	void	*data;

	map = NULL;
	while (list != NULL)
	{
		data = fun(list->data);
		new = ft_list_new(data);
		if (new == NULL || data == NULL)
		{
			del(data);
			ft_list_remove(new, NULL);
			ft_list_remove_all(&map, del);
			return (NULL);
		}
		ft_list_add_back(&map, new);
		list = list->next;
	}
	return (map);
}
