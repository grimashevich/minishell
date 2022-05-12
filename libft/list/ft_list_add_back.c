/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:10 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 13:34:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"

void	ft_list_add_back(t_list **list, t_list *new)
{
	if (*list == NULL)
		*list = new;
	else
		ft_list_last(*list)->next = new;
}
