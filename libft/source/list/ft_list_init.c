/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:03:33 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//		Creates a new list element.
t_list	*ft_list_init(void *data)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element == LIST_FAILED)
		return (LIST_FAILED);
	element->data = data;
	element->next = LIST_END;
	return (element);
}
