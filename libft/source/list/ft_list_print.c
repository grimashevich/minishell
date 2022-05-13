/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:10:28 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static size_t	count_number_of_character(t_list *head)
{
	size_t	i;

	i = 0;
	while (head != LIST_END)
	{
		i += ft_strlen(head->data) + 1;
		head = head->next;
	}
	return (i);
}

static void	copy_to_string(t_list *head, char *string)
{
	while (head != LIST_END)
	{
		ft_strcpy(head->data, string);
		string += ft_strlen(head->data) + 1;
		*(string - 1) = '\n';
		head = head->next;
	}
}

//	Prints the strings from the list.
//	Returns the number of printed characters.
int	ft_list_print(t_list *head, int fd)
{
	char	*string;
	size_t	number_of_character;
	ssize_t	printed;

	number_of_character = count_number_of_character(head);
	printed = number_of_character;
	string = (char *)malloc((number_of_character + 1) * sizeof(char));
	if (string == NULL)
		return (-1);
	copy_to_string(head, string);
	if (write(fd, string, number_of_character) != printed)
	{
		free(string);
		return (-1);
	}
	else
	{
		free(string);
		return (printed);
	}
}
