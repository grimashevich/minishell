/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_remove_by_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:59:25 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 18:49:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

void	ft_strings_remove_by_part(char ***strings, char *part)
{
	int	index;

	index = ft_strings_get_index(*strings, part);
	if (index == -1)
		return ;
	ft_strings_remove(strings, index);
}
