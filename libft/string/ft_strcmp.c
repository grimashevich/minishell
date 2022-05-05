/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:27 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:16:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

int	ft_strcmp(char *one, char *two)
{
	size_t	i;

	i = 0;
	while (one[i] == two[i] && one[i] != '\0')
		i += 1;
	return ((unsigned char)one[i] - (unsigned char)two[i]);
}
