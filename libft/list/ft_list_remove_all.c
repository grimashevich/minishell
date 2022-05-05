/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 19:58:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"

void	ft_list_remove_all(t_list **list, void (*del)(void *))
{
	t_list	*previous;
	t_list	*one;

	one = *list;
	*list = NULL;
	while (one != NULL)
	{
		previous = one;
		one = one->next;
		ft_list_remove(previous, del);
	}
}
