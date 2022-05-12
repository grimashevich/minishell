/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:15:03 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 23:17:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

int	ft_strings_replace(char **strings, char *string, int index)
{
	int	count;
	int	i;

	count = ft_strings_count(strings);
	if (index < 0 || index >= count)
		return (-1);
	i = 0;
	while (i < count)
	{
		if (i == index)
		{
			free(strings[i]);
			strings[i] = string;
			return (i);
		}
		i += 1;
	}
	return (-1);
}
