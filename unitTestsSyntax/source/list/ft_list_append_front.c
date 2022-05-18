/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_append_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 13:43:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//		Adds an element to the top of the list.
void	ft_list_append_front(t_list **head, t_list *element)
{
	element->next = *head;
	*head = element;
}
