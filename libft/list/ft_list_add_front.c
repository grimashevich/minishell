/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/10 17:59:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"
#include <unistd.h>

void	ft_list_add_front(t_list **list, t_list *new)
{
	new->next = *list;
	*list = new;
}
