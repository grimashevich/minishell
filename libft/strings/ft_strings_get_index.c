/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_get_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 04:08:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 18:17:22 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"

int	ft_strings_get_index(char **strings, char *part)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		if (ft_strncmp(strings[i], part, ft_strlen(part)) == 0)
		{	
			return (i);
		}
		i += 1;
	}
	return (-1);
}
