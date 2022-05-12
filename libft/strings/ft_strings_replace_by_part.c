/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_replace_by_part.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:07:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 18:45:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

int	ft_strings_replace_by_part(char **strings, char *string, char *part)
{
	int	index;

	index = ft_strings_get_index(strings, part);
	return (ft_strings_replace(strings, string, index));
}
