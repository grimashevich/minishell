/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:28:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/02 17:57:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>
#include <unistd.h>

static size_t	get_lenght(char **strings)
{
	size_t	i;

	i = 0;
	while (*strings != NULL)
	{
		i += ft_strlen(*strings++) + 1;
	}
	return (i);
}

static void	copy_to_string(char **strings, char *string)
{
	while (*strings != NULL)
	{
		ft_strcpy(*strings, string);
		string += ft_strlen(*strings) + 1;
		*(string - 1) = '\n';
		strings++;
	}
}

int	ft_strings_print(char **strings)
{
	char	*string;
	size_t	lenght;

	lenght = get_lenght(strings);
	string = (char *)malloc(lenght * sizeof(char));
	if (string == NULL)
		return (-1);
	copy_to_string(strings, string);
	if (write(1, string, lenght) != (ssize_t)lenght)
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
 