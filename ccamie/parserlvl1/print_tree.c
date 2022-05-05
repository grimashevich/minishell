
#include "../minishell.h"

void	print_tree(t_cmd *command, int id)
{
	t_cmd	*start;
	int		idid;
	int		i;

	printf("%d. ", id);
	idid = id;
	start = command;
	i = 0;
	while (command != NULL)
	{
		if (command->child == NULL)
			printf(" %s ------", command->command[0]);
		else
			printf("[%d]------", ++idid);
		command = command->next;
		i += 1;
	}



	printf(" 0\n");
	// while (i > 0)
	// {
	// 	// printf(" |       ");
	// 	i -= 1;
	// }
	// printf("\n");



	// command = start;
	// while (command != NULL)
	// {
	// 	if (command->child != NULL)
	// 		printf(" 1       ");
	// 	else
	// 		printf(" 0       ");
	// 	command = command->next;
	// }
	printf("\n");


	command = start;
	while (command != NULL)
	{
		if (command->child != NULL)
			print_tree(command->child, ++id);
		command = command->next;
	}
}
