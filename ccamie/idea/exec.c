#include "minishell.h"

void	exec_command(t_cmd *command)
{
	if (command->prev_operator == "&&" && g_ms.errno != 0)
		return ;
	if (command->prev_operator == "||" && g_ms.errno == 0)
		return ;
	if (command->prev_operator == "|")
	{
		// dup2
		
	}
	if (command->next_operator == "|")
	{
		// create pipe
		// dup2

	}
	if (command->outfile != NULL)
	{
		// create or open file
		// dup2

	}
	else if (command->container != NULL && command->container->outfd)
	{
		// dup2

	}
	if (command->infile != NULL)
	{
		// open file
		// dup2
		
	}
	else if (command->container != NULL && command->container->infd)
	{
		// dup2

	}
	// fork
	// open
	// dup2
	// access
	// exec
}

void	exec(t_tag *head)
{
	if (head->type == COMMAND)
	{
		exec_command(head->data);
	}
	else if (head->typez == CONTAINER)
	{
		container(head->data);
	}
}
