/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 13:43:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//		Removes all elements from the list.
void	ft_list_remove_all(t_list **head, void (*remove)(void *))
{
	while (*head != LIST_EMPTY)
	{
		ft_list_remove_first(head, remove);
	}
}
