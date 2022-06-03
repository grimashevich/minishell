/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cwd_antisplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:17:30 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/03 04:02:59 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

size_t	get_lenght(char **strings, int separator)
{
	size_t	lenght;
	int		i;

	lenght = 0;
	i = 0;
	while (strings[i] != NULL)
	{
		lenght += ft_strlen(strings[i]) + separator;
		i += 1;
	}
	return (lenght - separator);
}

void	copy_to_string(char **strings, char *string, char *separator)
{
	while (*strings != NULL)
	{
		ft_strcpy(*strings, string);
		string += ft_strlen(*strings);
		strings++;
		if (*strings == NULL)
			break ;
		ft_strcpy(separator, string);
		string += ft_strlen(separator);
	}
}

char	*ft_anti_split(char **strings, char *separator)
{
	size_t	lenght;
	char	*string;

	if (strings == NULL)
		return (NULL);
	if (*strings == NULL)
		return (NULL);
	if (separator == NULL)
		return (NULL);
	lenght = get_lenght(strings, ft_strlen(separator));
	string = (char *)malloc((lenght + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	copy_to_string(strings, string, separator);
	return (string);
}
