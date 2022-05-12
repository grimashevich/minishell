/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:17 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 19:58:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove(t_list *list, void (*del)(void *))
{
	if (del != NULL)
		del(list->data);
	free(list);
}
