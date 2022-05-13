/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:10:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		Converts a string to a list.
t_list	*ft_strings_to_list(char **strings)
{
	t_list	*list;
	t_list	*element;

	list = LIST_EMPTY;
	while (*strings != NULL)
	{
		element = ft_list_init(*strings);
		if (element == LIST_FAILED)
		{
			ft_list_remove(element, LIST_DO_NOT_FREE_DATA);
			ft_list_remove_all(&list, LIST_DO_NOT_FREE_DATA);
			return (LIST_FAILED);
		}
		ft_list_append(&list, element);
		strings++;
	}
	return (list);
}
