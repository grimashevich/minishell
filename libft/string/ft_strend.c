/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:35 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:17:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"

int	ft_strend(char *string, char *ending)
{
	int	lenght;
	int	offset;

	lenght = ft_strlen(ending);
	offset = ft_strlen(string) - lenght;
	if (offset < 0)
		return (0);
	if (ft_strncmp(string + offset, ending, lenght) == 0)
		return (1);
	else
		return (0);
}
