/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:10:28 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:10:32 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

static size_t	get_lenght(t_list *list)
{
	size_t	i;

	i = 0;
	while (list != NULL)
	{
		i += ft_strlen(list->data) + 1;
		list = list->next;
	}
	return (i);
}

static void	copy_to_string(t_list *list, char *string)
{
	while (list != NULL)
	{
		ft_strcpy(list->data, string);
		string += ft_strlen(list->data) + 1;
		*(string - 1) = '\n';
		list = list->next;
	}
}

int	ft_list_print(t_list *list, int fd)
{
	char	*string;
	size_t	lenght;

	lenght = get_lenght(list);
	string = (char *)malloc(sizeof(char) * (lenght + 1));
	if (string == NULL)
		return (-1);
	copy_to_string(list, string);
	if (write(fd, string, lenght) != (ssize_t)lenght)
	{
		free(string);
		return (-1);
	}
	else
	{
		free(string);
		return (0);
	}
}
