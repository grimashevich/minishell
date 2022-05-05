/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_current.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 17:03:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"

int	ft_list_remove_current(t_list **list, t_list *current, void (*del)(void *))
{
	t_list	*previous;

	if (*list == current)
	{
		*list = current->next;
	}
	else
	{
		previous = ft_list_prev(*list, current);
		if (previous == NULL)
			return (-1);
		previous->next = current->next;
	}
	ft_list_remove(current, del);
	return (0);
}
