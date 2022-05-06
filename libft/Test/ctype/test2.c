/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:59:01 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 15:50:39 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <ctype.h>
#include <stdio.h>

void	test(char *name, int (*org)(int character), int (*func)(int character))
{
	int		status;
	long	i;

	status = 0;
	i = -__INT_MAX__ - 1;
	while (i <= __INT_MAX__)
	{
		if (org(i) != func(i))
		{
			printf("\x1b[31mError\x1b[0m %s(\x1b[33m%03d\x1b[0m) expected: \x1b[33m%03d\x1b[0m returned: \x1b[33m%03d\x1b[0m\n", \
				name, (int)i, org(i), func(i));		
			status = 1;
		}
		i += 1;
	}
	if (status == 0)
	{
		printf("\x1b[32mDone\x1b[0m  %s\n", name);
	}
}

int	main(void)
{
	printf("launch Test 2 ctype\x1b[?25l\n");
	test("digittoint", digittoint, ft_digittoint);
	test("isalnum", isalnum, ft_isalnum);
	test("isalpha", isalpha, ft_isalpha);
	test("isascii", isascii, ft_isascii);
	test("isblank", isblank, ft_isblank);
	test("iscntrl", iscntrl, ft_iscntrl);
	test("isdigit", isdigit, ft_isdigit);
	test("isgraph", isgraph, ft_isgraph);
	test("islower", islower, ft_islower);
	test("isprint", isprint, ft_isprint);
	test("ispunct", ispunct, ft_ispunct);
	test("isspace", isspace, ft_isspace);
	test("isupper", isupper, ft_isupper);
	test("isxdigit", isxdigit, ft_isxdigit);
	test("toascii", toascii, ft_toascii);
	test("tolower", tolower, ft_tolower);
	test("toupper", toupper, ft_toupper);
	printf("\x1b[?25h");
}
