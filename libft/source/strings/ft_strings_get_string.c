/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_get_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:28:56 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 20:41:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		
char	*ft_strings_get_string(char **strings, char *part)
{
	while (*strings != NULL)
	{
		if (ft_strncmp(*strings, part, ft_strlen(part)) == 0)
		{	
			return (*strings);
		}
		strings++;
	}
	return (NULL);
}
