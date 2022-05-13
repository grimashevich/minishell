/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:49:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:13:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libtest/include/libtest.h"

void	launch_test(void);
void	print_test(void);

int	main(int argc, char **argv)
{
	char	*input;

	g_input = argv[1];
	g_output_file = argv[2];
	launch_test();
	print_test();
}
