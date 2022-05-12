/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/06 19:57:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

// #define LINE "(echo 1&& echo 2|| echo \"3 && echo 4 \" ;(echo 5 | echo 6)    )"
#define LINE "      (     echo 1 > file && echo 2 || (echo \"3MINECRAFT\" && (echo \"3 && echo 4 \" && echo 5 | echo 6) && echo WTF | echo 6) < file   )"
// #define LINE "           echo 1 && (echo 2 && (echo 2 && (echo 2 && echo 4)))"
// #define LINE "           echo 1&&echo 2||echo 3"
// #define LINE "           (echo 1 && echo 2) || echo 3"
// #define LINE "           echo 1 && (echo 2 || echo 3) && echo 4"

void	print_diagram(t_tag *head);
void	print_tree(t_tag *head);

void	tree_remove_all(t_tag **head)
{
	t_tag	*current;
	t_cmd	*command;
	t_cont	*container;
	int		i;

	current = *head;
	i = 0;
	while (current[i].type != END)
	{
		if (current[i].type == COMMAND)
		{
			command = current[i].data;
			ft_strings_remove_all(&command->command);
			free(command);
		}
		if (current[i].type == CONTAINER)
		{
			container = current[i].data;
			tree_remove_all(&container->tag);
			free(container);
		}
		i += 1;
	}
	free(*head);
	*head = NULL;
}

int	main(void)
{
	t_tag	*head;
	char	*line;

	printf("sizeof(t_cmd): %zu\n", sizeof(t_cmd));
	printf("sizeof(t_cmd *): %zu\n", sizeof(t_cmd *));
	printf("sizeof(t_cont): %zu\n", sizeof(t_cont));
	printf("sizeof(t_cont *): %zu\n", sizeof(t_cont *));
	printf("\x1b[32mInput:\x1b[0m\n");
	printf("+------------------------------------------------------------------------------+\n");
	printf("| %-77s|\n", LINE);
	printf("+------------------------------------------------------------------------------+\n");
	line = ft_strdup(LINE);
	if (line == NULL)
		return (1);
	head = parser(line);
	free(line);
	printf("\n");
	print_diagram(head);
	printf("\n");
	print_tree(head);
	tree_remove_all(&head);
	printf("\n");
	return (0);
}
