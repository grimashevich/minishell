/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:20 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <unistd.h>

int	ft_putstr_fd(char *string, int fd)
{
	if (string == NULL)
		return (-1);
	return (write(fd, string, ft_strlen(string)));
}
