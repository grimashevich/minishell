/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/05 19:53:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tag	*parser(char *line);

// void	test(char *line, int character)
// {
// 	t_cont	*head;

// 	head = parser(line);
// 	printf("\x1b[33mminishell: syntax error near unexpected token '%c'\x1b[0m\n", character);
// 	printf("-------------------------------------------------\n");
// }

// int	main(void)
// {
// 	test("echo 1 (", '(');
// 	test("echo 1 )", ')');
// 	test("echo 1 )(", ')');
// 	test("echo 1 ()", '(');
// 	test("echo 1 ) (", ')');
// 	test("echo 1 ( )", '(');
// 	test("echo 1 && () && echo 2", ')');
// 	test("echo 1 && )( && echo 2", ')');
// 	test("echo 1 && ( ) && echo 2", ')');
// 	test("echo 1 && ) ( && echo 2", ')');
// 	return (0);
// }

#define LINE "      (     echo 1 && echo 2 || echo \"3 && echo 4 \" ; (echo 5 | echo 6)    )"
// #define LINE "           echo 1 && echo 2 "

int	main(void)
{
	t_tag	*head;
	char	*line;

	printf("|------------------------------------------------------------------------------|\n");
	printf("| %-77s|\n", LINE);
	printf("|------------------------------------------------------------------------------|\n");
	printf("\n");

	line = strdup(LINE);
	if (line == NULL)
		return (1);
	head = parser(line);
	return (0);
}
