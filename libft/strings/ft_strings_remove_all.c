/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_remove_all.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:28:51 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/03 16:28:52 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_strings.h"
#include <stdlib.h>

void	ft_strings_remove_all(char ***strings)
{
	char	**temporary;

	temporary = *strings;
	while (*temporary != NULL)
		free(*temporary++);
	free(*strings);
	*strings = NULL;
}
