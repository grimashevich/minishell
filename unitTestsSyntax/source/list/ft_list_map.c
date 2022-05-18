/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:31 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 13:43:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//		Creates a new list with new data.
t_list	*ft_list_map(\
		t_list *head, void *(*function)(void *), void (*remove)(void *))
{
	t_list	*list;
	t_list	*element;
	void	*data;

	list = LIST_EMPTY;
	while (head != LIST_END)
	{
		data = function(head->data);
		element = ft_list_init(data);
		if (element == LIST_FAILED || data == NULL)
		{
			remove(data);
			ft_list_remove(element, LIST_DO_NOT_FREE_DATA);
			ft_list_remove_all(&list, remove);
			return (LIST_FAILED);
		}
		ft_list_append(&list, element);
		head = head->next;
	}
	return (list);
}
