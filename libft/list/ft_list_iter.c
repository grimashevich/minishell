/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:22 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/10 17:59:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"

void	ft_list_iter(t_list *list, void (*fun)(void *))
{
	while (list != NULL)
	{
		fun(list->data);
		list = list->next;
	}
}
