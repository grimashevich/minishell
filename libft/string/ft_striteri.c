/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:54:20 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/16 22:54:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

void	ft_striteri(char *string, void (*func)(unsigned int, char*))
{
	unsigned int	i;

	if (string == NULL || func == NULL)
		return ;
	i = 0;
	while (string[i])
	{
		func(i, &string[i]);
		i += 1;
	}
}
