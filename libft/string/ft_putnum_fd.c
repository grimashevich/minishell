/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:16 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_putnum_fd(int num, int fd)
{
	char	*string;
	ssize_t	i;

	string = ft_itoa(num);
	if (string == NULL)
		return (-1);
	i = write(fd, string, ft_strlen(string));
	free(string);
	return (i);
}
