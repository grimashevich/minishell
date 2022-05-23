/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//		Removes the last element.
void	ft_list_remove_last(t_list **head, void (*del)(void *))
{
	t_list	*element;

	if ((*head)->next == LIST_END)
	{
		element = *head;
		*head = LIST_EMPTY;
		ft_list_remove(element, del);
	}
	else
	{
		element = ft_list_last(*head);
		ft_list_remove(element, del);
	}
}
