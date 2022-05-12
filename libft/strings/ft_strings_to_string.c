/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:13:27 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:13:29 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

static size_t	get_lenght(char **strings, int splitter)
{
	size_t	lenght;
	int		i;

	lenght = 0;
	i = 0;
	while (strings[i] != NULL)
	{
		lenght += ft_strlen(strings[i]) + splitter;
		i += 1;
	}
	return (lenght - splitter);
}

static void	copy_to_string(char **strings, char *string, char *splitter)
{
	while (*strings != NULL)
	{
		ft_strcpy(*strings, string);
		string += ft_strlen(*strings);
		strings++;
		if (*strings == NULL)
			break ;
		ft_strcpy(splitter, string);
		string += ft_strlen(splitter);
	}
}

char	*ft_strings_to_string(char **strings, char *splitter)
{
	size_t	lenght;
	char	*string;

	if (strings == NULL)
		return (NULL);
	if (*strings == NULL)
		return (NULL);
	if (splitter == NULL)
		return (NULL);
	lenght = get_lenght(strings, ft_strlen(splitter));
	string = (char *)malloc((lenght + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	copy_to_string(strings, string, splitter);
	return (string);
}
