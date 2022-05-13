/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_from_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Removes an element from the list.
int	ft_list_remove_from_list(\
	t_list **head, t_list *element, void (*remove)(void *))
{
	t_list	*previous;

	if (*head == element)
	{
		*head = element->next;
		ft_list_remove(element, remove);
		return (0);
	}
	else
	{
		previous = ft_list_prev(*head, element);
		if (previous == LIST_NOT_FOUND)
			return (-1);
		previous->next = element->next;
		return (0);
	}
}
