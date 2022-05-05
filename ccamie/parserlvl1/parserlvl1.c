/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserlvl1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:27:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/02 18:46:06 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	skip_brackets(char *string)
{
	int	bracket;
	int	i;

	bracket = 1;
	i = 1;
	while (bracket != 0 && string[i] != '\0')
	{
		if (string[i] == '(')
			bracket += 1;
		if (string[i] == ')')
		{
			bracket -= 1;
		}
		i += 1;
	}
	if (bracket != 0)
	{
		printf("minishell: syntax error near unexpected token `('\n");
		exit(1);
	}
	else
	{
		return (i);
	}
}

static size_t	get_count(char *string)
{
	size_t	i;

	i = 1;
	while (*string != '\0')
	{
		if (*string == ')')
		{
			printf("minishell: syntax error near unexpected token `)'\n");
			exit(1);
		}
		else if (*string == '(')
		{
			string += skip_brackets(string);
		}
		else if (ft_strncmp(string, "&&", 2) == 0)
		{
			string += 2;
			i += 1;
		}
		else if (ft_strncmp(string, "||", 2) == 0)
		{
			string += 2;
			i += 1;
		}
		else if (ft_strncmp(string, ";", 1) == 0)
		{
			string += 2;
			i += 1;
		}
		else if (*string == '|')
		{
			string += 1;
			i += 1;
		}
		else
		{
			string += 1;
		}
	}
	return (i);
}

static char 	*get_string(char *string, int lenght)
{
	char	*temporary1;
	char	*temporary2;

	temporary1 = ft_substr(string, 0, lenght);
	if (temporary1 == NULL)
	{
		perror(NULL);
		exit(1);
	}
	temporary2 = ft_strtrim(temporary1, " ");
	if (temporary2 == NULL)
	{
		perror(NULL);
		exit(1);
	}
	free(temporary1);
	return(temporary2);
}

static void	copy_to_strings(char **strings, char *string, int count)
{
	int		i;
	int		j;
	int		skip;

	j = 0;
	while (j < count)
	{
		skip = 0;
		i = 0;
		while (string[i] != '\0')
		{
			if (string[i] == '(')
			{
				i += skip_brackets(&string[i]);
			}
			else if (ft_strncmp(string + i, "&&", 2) == 0)
			{
				skip = i + 2;
				break ;
			}
			else if (ft_strncmp(string + i, "||", 2) == 0)
			{
				skip = i + 2;
				break ;
			}
			else if (ft_strncmp(string + i, ";", 1) == 0)
			{
				skip = i + 1;
				break ;
			}
			else if (*(string + i) == '|')
			{
				skip = i + 1;
				break ;
			}
			else
			{
				i += 1;
			}
		}
		strings[j] = get_string(string, i);
		string += skip;
		j += 1;
	}
	strings[j] = NULL;
}

static char	**split_by_operators(char *string)
{
	char	**strings;
	size_t	count;

	count = get_count(string);
	// printf("count: %zu\n", count);
	strings = (char **)malloc((count + 1) * sizeof(char *));
	if (strings == NULL)
	{
		perror(NULL);
		exit(1);
	}
	copy_to_strings(strings, string, count);
	return (strings);
}


char	*md_strtrim(char *string)
{
	size_t	lenght;

	if (*string && *string == '(')
		string += 1;
	lenght = ft_strlen(string) - 1;
	if (lenght != 0 && string[lenght] == ')')
	{
		// printf("HWA: %c\n", string[lenght]);
		lenght -= 1;
	}
	return (ft_substr(string, 0, lenght + 1));
}

static void	parser(char *string, t_cmd *command)
{
	char	**strings;
	int		j;

	strings = split_by_operators(string);
	j = 0;
	while (strings[j] != NULL)
	{
		if (strings[j][0] == '(')
		{
			char	*temporary;

			temporary = md_strtrim(strings[j]);
			if (temporary == NULL)
			{
				perror(NULL);
				exit(1);
			}
			command->child = (t_cmd *)malloc(sizeof(t_cmd));
			if (command->child == NULL)
			{
				perror(NULL);
				exit(1);
			}
			parser(temporary, command->child);
			if (strings[j + 1] == NULL)
			{
				command->next = NULL;
				break ;
			}
			command->next = (t_cmd *)malloc(sizeof(t_cmd));
			if (command->next == NULL)
			{
				perror(NULL);
				exit(1);
			}
			command = command->next;
		}
		else
		{
			char	**temporary;

			temporary = (char **)malloc(2 * sizeof(char *));
			temporary[0] = strings[j];
			temporary[1] = NULL;
			command->command = temporary;
			command->child = NULL;
			if (strings[j + 1] == NULL)
			{
				command->next = NULL;
				break ;
			}
			command->next = (t_cmd *)malloc(sizeof(t_cmd));
			if (command->next == NULL)
			{
				perror(NULL);
				exit(1);
			}
			command = command->next;
		}
		j += 1;
	}
}

t_cmd	*parserlvl1(char *string)
{
	t_cmd	*command;

	command = (t_cmd *)malloc(sizeof(t_cmd));
	if (command == NULL)
	{
		perror(NULL);
		exit(1);
	}
	parser(string, command);
	return (command);
}
