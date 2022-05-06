/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:59:01 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 16:31:26 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void	test(char *name, int (*org)(int character), int (*func)(int character))
{
	int	status;
	int	i;

	status = 0;
	i = -__SCHAR_MAX__ - 1;
	while (i <= __SCHAR_MAX__)
	{
		if (org(i) != func(i))
		{
			printf("\x1b[31mKO\x1b[0m ");
			printf("%s(\x1b[33m%03d\x1b[0m) ", name, i);
			printf("expected: \x1b[33m%03d\x1b[0m ", org(i));
			printf("returned: \x1b[33m%03d\x1b[0m\n", func(i));
			status = 1;
		}
		i += 1;
	}
	if (status == 0)
	{
		printf("\x1b[32mOK\x1b[0m %s\n", name);
	}
}

int	main(int argc, char **argv)
{
	printf("launch Test 1 ctype\x1b[?25l\n");
	(void)argv;
	if (argc == 1)
	{
		test("ft_digittoint", digittoint, ft_digittoint);
		test("ft_isalnum", isalnum, ft_isalnum);
		test("ft_isalpha", isalpha, ft_isalpha);
		test("ft_isascii", isascii, ft_isascii);
		test("ft_isblank", isblank, ft_isblank);
		test("ft_iscntrl", iscntrl, ft_iscntrl);
		test("ft_isdigit", isdigit, ft_isdigit);
		test("ft_isgraph", isgraph, ft_isgraph);
		test("ft_islower", islower, ft_islower);
		test("ft_isprint", isprint, ft_isprint);
		test("ft_ispunct", ispunct, ft_ispunct);
		test("ft_isspace", isspace, ft_isspace);
		test("ft_isupper", isupper, ft_isupper);
		test("ft_isxdigit", isxdigit, ft_isxdigit);
		test("ft_toascii", toascii, ft_toascii);
		test("ft_tolower", tolower, ft_tolower);
		test("ft_toupper", toupper, ft_toupper);
	}
	else
	{
		
	}
	printf("\x1b[?25h");
}
