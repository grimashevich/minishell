#include "minishell.h"

static void	is_this_an_operator(char **line, int *number_of_operators)
{
	if (ft_strncmp(*line, "&&", 2) == 0)
	{
		*line += 2;
	}
	else if (ft_strncmp(*line, "||", 2) == 0)
	{
		*line += 2;
	}
	else if (**line == '|')	
	{
		*line += 1;
	}
	else if (**line == ';')	
	{
		*line += 1;
	}
	else
	{
		*line += 1;
		return ;
	}
	*number_of_operators += 1;
}

static void	is_this_a_brace(char **line)
{
	int	number_of_open_brackets;

	if (**line != '(')
		return ;
	*line += 1;
	printf("\x1b[33mThe opening bracket is found:\x1b[0m %s\n", *line - 1);
	number_of_open_brackets = 1;
	while (number_of_open_brackets != 0) 
	{
		if (**line == '(')
		{
			printf("\x1b[33mThe opening bracket is found:\x1b[0m %s\n", *line - 1);
			number_of_open_brackets += 1;
		}
		if (**line == ')')
		{
			printf("\x1b[33mThe closing bracket is found:\x1b[0m %s\n", *line);
			number_of_open_brackets -= 1;
		}
		*line += 1;
	}
}

static void	is_this_a_single_quotation_mark(char **line)
{
	if (**line != '\'')
		return ;
	*line += 1;
	printf("\x1b[33mThe opening single quotation mark is found:\x1b[0m %s\n", *line - 1);
	while (**line != '\'')
	{
		*line += 1;
	}
	*line += 1;
	printf("\x1b[33mThe closing single quotation mark is found:\x1b[0m %s\n", *line - 1);
}

static void	is_this_a_double_quotation_mark(char **line)
{
	if (**line != '\"')
		return ;
	*line += 1;
	printf("\x1b[33mThe opening double quotation mark is found:\x1b[0m %s\n", *line - 1);
	while (**line != '\"')
	{
		*line += 1;
	}
	*line += 1;
	printf("\x1b[33mThe closing double quotation mark is found:\x1b[0m %s\n", *line - 1);
}

int	count_the_number_of_operators(char *line)
{
	int	number_of_operators;

	number_of_operators = 0;
	while (*line != '\0')
	{
		is_this_an_operator(&line, &number_of_operators);
		is_this_a_brace(&line);
		is_this_a_single_quotation_mark(&line);
		is_this_a_double_quotation_mark(&line);
	}
	printf("\x1b[33mNumber of operators:\x1b[0m %d\n", number_of_operators);
	return (number_of_operators);
}
