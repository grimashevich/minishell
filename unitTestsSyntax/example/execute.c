/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:00:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/18 15:35:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

#define TRUE	1
#define FALSE	0

enum e_operator
{
	EMPTY,
	AND,
	OR,
	PIPE,
	SEQUENCE
};

int	ft_isalnum(int character)
{
	return ((character >= 48 && character <= 57) + \
			(character >= 65 && character <= 90) + \
			(character >= 97 && character <= 122));
}

int	ft_isspace(int character)
{
	return ((character >= 9 && character <= 13) || character == 32);
}

int	is_this_operator(char **string)
{
	if (**string == '&' && *(*string + 1) == '&')
	{
		*string += 2;
		return (AND);
	}
	else if (**string == '|' && *(*string + 1) == '|')
	{
		*string += 2;
		return (OR);
	}
	else if (**string == '|')
	{
		*string += 1;
		return (PIPE);
	}
	else if (**string == ';')	
	{
		*string += 1;
		return (SEQUENCE);
	}
	else
	{
		*string += 1;
		return (EMPTY);
	}
}












int	check_single_quotation_mark(char *string)
{
	int	number_of_single_quotation_mark;

	number_of_single_quotation_mark = 0;
	while (*string !='\0')
	{
		if (*string == '\'')
		{
			number_of_single_quotation_mark += 1;
		}
		string += 1;
	}
	if (number_of_single_quotation_mark % 2 == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int	check_double_quotation_mark(char *string)
{
	int	number_of_double_quotation_mark;

	number_of_double_quotation_mark = 0;
	while (*string !='\0')
	{
		if (*string == '\"')
		{
			number_of_double_quotation_mark += 1;
		}
		string += 1;
	}
	if (number_of_double_quotation_mark % 2 == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int	check_quotation_mark_syntax(char *string)
{
	if (check_single_quotation_mark(string) != 0)
	{
		// printf("minishell: syntax error near unexpected token '\''\n");
		write(1, "minishell: syntax error near unexpected token '\''", 49);	// '\n'
		return (-1);
	}
	if (check_double_quotation_mark(string) != 0)
	{
		// printf("minishell: syntax error near unexpected token '\"'\n");
		write(1, "minishell: syntax error near unexpected token '\"'", 49); // '\n'
		return (-1);
	}
	return (0);
}





















int	skip_single_quotation_mark(char *string)
{
	int	i;

	i = 1;
	while (string[i] != '\'')
	{
		i += 1;
	}
	return (i);
}

int	skip_double_quotation_mark(char *string)
{
	int	i;

	i = 1;
	while (string[i] != '\"')
	{
		i += 1;
	}
	return (i);
}

int	check_open_and_close(char *string)
{
	int	number_of_open_parenthesis;

	number_of_open_parenthesis = 0;
	while (*string != '\0')
	{
		if (*string == '\'')
		{
			string += skip_single_quotation_mark(string);
		}
		if (*string == '\"')
		{
			string += skip_double_quotation_mark(string);
		}
		if (*string == '(')
		{
			number_of_open_parenthesis += 1;
		}
		else if (*string == ')')
		{
			number_of_open_parenthesis -= 1;
		}
		string += 1;
	}
	if (number_of_open_parenthesis > 0)
	{
		// printf("minishell: syntax error near unexpected token '('\n");
		write(1, "minishell: syntax error near unexpected token '('", 49); // '\n'
		return (-1);
	}
	if (number_of_open_parenthesis < 0)
	{
		// printf("minishell: syntax error near unexpected token ')'\n");
		write(1, "minishell: syntax error near unexpected token ')'", 49); // '\n'
		return (-1);
	}
	return (0);
}

int	check_parentheses_befor_operator(char *string)
{
	int	iscommand;
	int	operator;
	int	was_operator;

	iscommand = FALSE;
	operator = EMPTY;
	was_operator = EMPTY;
	while (*string != '\0')
	{
		if (*string == '\'')
		{
			string += skip_single_quotation_mark(string);
		}
		if (*string == '\"')
		{
			string += skip_double_quotation_mark(string);
		}
		if (ft_isalnum(*string) == TRUE)
		{
			iscommand = TRUE;
		}
		if (*string == '(' && iscommand == TRUE)
		{
			// printf("minishell: syntax error near unexpected token '('\n");
			write(1, "minishell: syntax error near unexpected token '('", 49); // '\n'
			return (-1);
		}
		operator = is_this_operator(&string);
		if (operator != EMPTY)
		{
			was_operator = operator;
			iscommand = FALSE;
		}
	}
	return (0);
}

int	get_lenght(char *string)
{
	int	i;

	i = 0;
	while (ft_isalnum(string[i]) == TRUE)
	{
		i += 1;
	}
	return (i);
}

int	check_parentheses_after_operator(char *string)
{
	int	iscommand;
	int	operator;
	int	was_operator;

	iscommand = FALSE;
	operator = EMPTY;
	was_operator = EMPTY;
	while (*string != '\0')
	{
		while (*string != ')' && *string != '\0')
		{
			if (*string == '\'')
			{
				string += skip_single_quotation_mark(string);
			}
			if (*string == '\"')
			{
				string += skip_double_quotation_mark(string);
			}
			string += 1;
		}
		if (*string == '\0')
		{
			return (0);
		}
		else
		{
			iscommand = FALSE;
		}
		while (operator == EMPTY && *string != '\0')
		{
			if (*string == '\'')
			{
				string += skip_single_quotation_mark(string);
			}
			if (*string == '\"')
			{
				string += skip_double_quotation_mark(string);
			}
			while (*string == '>' || *string == '<')
			{
				string += 1;
				while (ft_isspace(*string) == TRUE)
				{
					string += 1;
				}
				while (ft_isalnum(*string) == TRUE)
				{
					string += 1;
				}
				while (ft_isspace(*string) == TRUE)
				{
					string += 1;
				}
			}
			if (ft_isalnum(*string) == TRUE)
			{
				// printf("minishell: syntax error near unexpected token '('\n");
				write(1, "minishell: syntax error near unexpected token '", 47); // '\n'
				write(1, string, get_lenght(string));
				write(1, "''", 1);
				return (-1);
			}
			operator = is_this_operator(&string);
		}
	}
	return (0);
}

int	check_syntax_of_parentheses(char *string)
{
	if (check_open_and_close(string) != 0)
	{
		return (-1);
	}
	if (check_parentheses_befor_operator(string) != 0)
	{
		return (-1);
	}
	if (check_parentheses_after_operator(string) != 0)
	{
		return (-1);
	}
	return (0);
}





























void	print_error(int operator)
{
	if (operator == AND)
	{
		// printf("minishell: syntax error near unexpected token '&&'\n");
		write(1, "minishell: syntax error near unexpected token '&&'", 50); // '\n'
	}
	else if (operator == OR)
	{
		// printf("minishell: syntax error near unexpected token '||'\n");
		write(1, "minishell: syntax error near unexpected token '||'", 50); // '\n'
	}
	else if (operator == PIPE)
	{
		// printf("minishell: syntax error near unexpected token '|'\n");
		write(1, "minishell: syntax error near unexpected token '|'", 49); // '\n'
	}
	else if (operator == SEQUENCE)
	{
		// printf("minishell: syntax error near unexpected token ';'\n");
		write(1, "minishell: syntax error near unexpected token ';'", 49); // '\n'
	}
}

int	check_syntax_of_operators(char *string)
{
	int	iscommand;
	int	operator;
	int	was_operator;

	iscommand = FALSE;
	operator = EMPTY;
	was_operator = EMPTY;
	while (*string != '\0')
	{
		if (*string == '\'')
		{
			string += skip_single_quotation_mark(string);
		}
		if (*string == '\"')
		{
			string += skip_double_quotation_mark(string);
		}
		if (ft_isalnum(*string) == TRUE)
		{
			iscommand = TRUE;
		}
		operator = is_this_operator(&string);
		if (operator != EMPTY)
		{
			if (iscommand == FALSE)
			{
				print_error(operator);
				return (-1);
			}
			else
			{
				was_operator = operator;
				iscommand = FALSE;
			}
		}
	}
	if (operator != EMPTY || iscommand == FALSE)
	{
		print_error(was_operator);
		return (-1);
	}
	return (0);
}



































int	check_syntax_of_redirect_outfile(char *string)
{
	// int	i;

	while (*string !='\0')
	{
		if (*string == '>')
		{
			// i = 0;
			string += 1;
			if (*string == '>')
			{
				string += 1;
			}
			while (ft_isspace(*string) == TRUE)
			{
				string += 1;
			}
			if (ft_isalnum(*string) != TRUE)
			{
				if (*(string + 1) == '>')
				{
					// printf("minishell: syntax error near unexpected token '>>'\n");
					write(1, "minishell: syntax error near unexpected token '>>'", 50); // '\n'
					return (-1);
				}
				else
				{
					// printf("minishell: syntax error near unexpected token '>'\n");
					write(1, "minishell: syntax error near unexpected token '>'", 49); // '\n'
					return (-1);
				}
			}
		}
		string += 1;
	}
	return (0);
}

int	check_syntax_of_redirect_infile(char *string)
{
	int	i;

	while (*string !='\0')
	{
		if (*string == '<')
		{
			i = 0;
			while (string[i] == '<')
			{
				i += 1;
			}
			if (i == 4)
			{
				// printf("minishell: syntax error near unexpected token '<'\n");
				write(1, "minishell: syntax error near unexpected token '<'", 50); // '\n'
				return (-1);
			}
			if (i == 5)
			{
				// printf("minishell: syntax error near unexpected token '<<'\n");
				write(1, "minishell: syntax error near unexpected token '<<'", 51); // '\n'
				return (-1);
			}
			if (i >= 6)
			{
				// printf("minishell: syntax error near unexpected token '<<<'\n");
				write(1, "minishell: syntax error near unexpected token '<<<'", 51); // '\n'
				return (-1);
			}
			*string += i;
		}
		string += 1;
	}
	return (0);
}

int	check_syntax_of_redirect(char *string)
{
	if (check_syntax_of_redirect_outfile(string) != 0)
	{
		return (-1);
	}
	if (check_syntax_of_redirect_infile(string) != 0)
	{
		return (-1);
	}
	return (0);
}



























int	check_syntax(char *string)
{
	if (check_quotation_mark_syntax(string) != 0)
	{
		return (-1);
	}
	if (check_syntax_of_parentheses(string) != 0)
	{
		return (-1);
	}
	if (check_syntax_of_operators(string) != 0)
	{
		return (-1);
	}
	if (check_syntax_of_redirect(string) != 0)
	{
		return (-1);
	}
	return (0);
}

void	execute(void)
{
	g_data.returned = check_syntax(g_data.string);
	g_data.output = get_value_output();
}
