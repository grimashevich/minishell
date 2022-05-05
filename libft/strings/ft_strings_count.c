/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:28:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 16:56:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"

size_t	ft_strings_count(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i] != NULL)
		i += 1;
	return (i);
}
