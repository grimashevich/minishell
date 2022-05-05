/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserlvl1 copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:27:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 16:40:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	get_count(char *string)
{
	size_t	i;
	int		bracket;

	i = 0;
	while (*string != '\0')
	{
		if (*string == ')')
		{
			printf("bash: syntax error near unexpected token `)'\n");
			return (0);
		}
		if (*string == '(')
		{
			bracket = 1;
			string++;
			while (bracket != 0 && *string != '\0')
			{
				// printf("string[i]: %c, bracket: %d\n", string[i], bracket);
				if (*string == '(')
					bracket += 1;
				if (*string == ')')
					bracket -= 1;
				string++;
			}
			if (bracket != 0 && *string == '\0')
			{
				printf("bash: syntax error near unexpected token `('\n");
				return (0);
			}
		}
		if (ft_strncmp(string, "&&", 2) == 0)
		{
			string++;
			i += 1;
		}
		else if (ft_strncmp(string, "||", 2) == 0)
		{
			string++;
			i += 1;
		}
		else if (ft_strncmp(string, ";", 1) == 0)
		{
			string++;
			i += 1;
		}
		else if (string[0] == '|' && string[1] != '|')
		{
			i += 1;
		}
		string++;
	}
	return (i);
}

void	copy_to_array(char **strings, char *string, int count)
{
	char	*temporary;
	int		i;
	int		j;
	int		c;

	int		bracket;

	j = 0;
	while (j < count)
	{
		i = 0;
		while (string[i] != '\0')
		{
			if (string[i] == '(')
			{
				bracket = 1;
				i += 1;
				while (bracket != 0 && string[i] != '\0')
				{
					// printf("string[i]: %c, bracket: %d\n", string[i], bracket);
					if (string[i] == '(')
						bracket += 1;
					if (string[i] == ')')
						bracket -= 1;
					i += 1;
				}
			}
			if (ft_strncmp(string + i, "&&", 2) == 0)
			{
				c = i + 2;
				break ;
			}
			else if (ft_strncmp(string + i, "||", 2) == 0)
			{
				c = i + 2;
				break ;
			}
			else if (ft_strncmp(string + i, ";", 1) == 0)
			{
				c = i + 1;
				// printf("how are you?\n");
				break ;
			}
			else if ((string + i)[0] == '|' && (string + i)[1] != '|')
			{
				c = i + 1;
				break ;
			}
			i += 1;
		}
		temporary = ft_substr(string, 0, i);
		strings[j] = ft_strtrim(temporary, " ");
		free(temporary);
		// printf("i: %d\n", i);
		// printf("strings[j]: %s\n", strings[j]);
		if (strings[j] == NULL)
		{
			// clear
			return ;
		}
		string += c;
		j += 1;
	}
	strings[j] = NULL;
}

char	**split_by_operators(char *string)
{
	char	**strings;
	size_t	count;

	count = get_count(string);
	if (count == 0)
		return (NULL);
	printf("count operators: %zu\n", count);
	strings = (char **)malloc((count + 2) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	copy_to_array(strings, string, count + 1);
	return (strings);
}

t_cmd	*parserlvl1(char *string);

void	recursion(char *string, t_cmd *command)
{
	char	**strings;
	int		i;

	// printf("command---------------%p\n", command);
	strings = split_by_operators(string);
	if (strings == NULL)
		return ; 
	ft_strings_print(strings);
	i = 0;
	while (strings[i] != NULL)
	{
		if (strings[i][0] == '(')
		{
			command->child = (t_cmd *)malloc(sizeof(t_cmd));
			if (command->child == NULL)
			{
				// clear
				return ;
			}
			// printf("child--------%s\n", strings[i]);
			// printf("command->child--------%p\n", command->child);
			recursion(ft_strtrim(strings[i], "()"), command->child);
			command->next = (t_cmd *)malloc(sizeof(t_cmd));
			if (command->next == NULL)
			{
				// clear
				return ;
			}
			command = command->next;
		}
		else
		{
			char	**temp;

			// printf("comm--------%s\n", strings[i]);
			temp = malloc(2 * sizeof(char *));
			temp[0] = strings[i];
			command->command = temp;
			command->child = NULL;
			if (strings[i + 1] == NULL)
			{
				command->next = NULL;
				break ;
			}
			command->next = (t_cmd *)malloc(sizeof(t_cmd));
			if (command->next == NULL)
			{
				// clear
				return ;
			}
			command = command->next;
		}
		i += 1;
	}
}

t_cmd	*parserlvl1(char *string)
{
	t_cmd	*command;

	command = (t_cmd *)malloc(sizeof(t_cmd));
	if (command == NULL)
	{
		// clear
		return (NULL);
	}
	recursion(string, command);
	return (command);
}

void	print_tree(t_cmd *command, int id)
{
	t_cmd	*start;
	int		i;

	start = command;
	i = 0;
	printf("%s\n", command->command[0]);
	printf("%p\n", command->next);
	printf("%p\n", command->next->next->command);
	// printf("%p\n", command->next->next->next);
	while (command != NULL)
	{
		// printf("%p\n", command->child);
		if (command->child == NULL)
			printf(" 1 ------");
		else
			printf("[%d]------", id++);
		command = command->next;
		i += 1;
	}
	printf(" 0\n");
	while (i > 0)
	{
		printf(" |       ");
		i -= 1;
	}
	printf("\n");
	command = start;
	while (command != NULL)
	{
		if (command->child != NULL)
		{
			// start = command->child;
			printf(" 1       ");
		}
		else
			printf(" 0       ");
		command = command->next;
	}
	printf("\n");
	command = start;
	printf("\n");
	while (command != NULL)
	{
		if (command->child != NULL)
		{
			print_tree(command->child, id + 1);
		}
		command = command->next;
	}

	// printf("          |\n");

	
	// i = 0;
	// while (command != NULL)
	// {
	// 	if (command->child == NULL)
	// 		printf(" 1 ------");
	// 	else
	// 		printf("[ ]------");
	// 	command = command->next;
	// 	i += 1;
	// }
	// printf(" 0\n");
	// while (i > 0)
	// {
	// 	printf(" |       ");
	// 	i -= 1;
	// }
	// printf("\n");
	// command = start;
	// while (command != NULL)
	// {
	// 	if (command->child != NULL)
	// 	{
	// 		start = command->child;
	// 		printf(" 1       ");
	// 	}
	// 	else
	// 		printf(" 0       ");
	// 	command = command->next;
	// }
	// printf("\n");
}