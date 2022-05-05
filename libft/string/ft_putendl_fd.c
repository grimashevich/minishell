/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_putendl_fd(char *string, int fd)
{
	ssize_t	i;

	string = ft_strjoin(string, "\n");
	if (string == NULL)
		return (-1);
	i = write(fd, string, ft_strlen(string));
	free(string);
	return (i);
}
