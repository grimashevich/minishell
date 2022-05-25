/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnvtosh <ivnvtosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:48 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/15 16:38:59 by ivnvtosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		
size_t	ft_strlen(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
		i += 1;
	return (i);
}