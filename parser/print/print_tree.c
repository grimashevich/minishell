#include "../../minishell.h"

void	print_operator(int operator)
{
	if (operator == AND)
	{
		printf("&&");
	}
	else if (operator == OR)
	{
		printf("||");
	}
	else if (operator == PIPE)
	{
		printf("|");
	}
	else if (operator == SEQUENCE)
	{
		printf(";");
	}
	else if (operator == EMPTY)
	{
		printf("-");
	}

}

void	print_tree(t_tag *head)
{
	t_cont	*container;
	t_cmd	*command;
	int		i;

	i = 0;
	while (1)
	{
		if (head[i].type == COMMAND)
		{
			command = head[i].data;
			print_operator(command->prev_operator);
			printf("\x1b[34m %s \x1b[0m", command->command[0]);
			// printf("\x1b[34m COMMAND \x1b[0m");
			print_operator(command->next_operator);
		}
		else if (head[i].type == CONTAINER)
		{
			container = head[i].data;
			print_operator(container->prev_operator);
			// printf("\x1b[34m CONTAINER \x1b[0m");
			printf(" (");
			print_tree(container->tag);
			printf(") ");
			print_operator(container->next_operator);
		}
		else if (head[i].type == END)
		{
			// printf("\x1b[41m❌\x1b[0m");
			break ;
		}
		i += 1;
	}
	// i = 0;
	// while (1)
	// {
	// 	if (head[i].type == CONTAINER)
	// 	{
	// 		container = (t_cont *)head[i].data;
	// 		print_tree(container->tag);
	// 	}
	// 	else if (head[i].type == END)
	// 	{
	// 		break ;
	// 	}
	// 	i += 1;
	// }
	// printf("\n");
}
