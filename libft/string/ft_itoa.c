/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:08 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string.h"
#include <stdlib.h>

static size_t	nbrlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*s;
	int		slen;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	slen = nbrlen(num);
	s = (char *)malloc(sizeof(*s) * (slen + 1));
	if (s == NULL)
		return (NULL);
	s[slen--] = 0;
	if (num == 0)
		s[0] = 48;
	if (num < 0)
	{
		s[0] = 45;
		num = -num;
	}
	while (num)
	{
		s[slen--] = num % 10 + 48;
		num /= 10;
	}
	return (s);
}
