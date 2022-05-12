/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:00:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/10 17:58:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"

t_list	*ft_list_prev(t_list *list, t_list *current)
{
	while (list != NULL && list->next != current)
		list = list->next;
	return (list);
}
