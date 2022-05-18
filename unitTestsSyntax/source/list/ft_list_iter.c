/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:22 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 13:43:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//		Creates new data.
void	ft_list_iter(t_list *head, void (*function)(void *))
{
	while (head != LIST_END)
	{
		function(head->data);
		head = head->next;
	}
}
