/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:00:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 13:43:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//		Returns the previous element from the list.
t_list	*ft_list_prev(t_list *head, t_list *element)
{
	while (head != LIST_END && head->next != element)
	{
		head = head->next;
	}
	if (head == LIST_END)
	{
		return (LIST_NOT_FOUND);
	}
	else
	{
		return (head);
	}
}
