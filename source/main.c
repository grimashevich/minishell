/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:45:25 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 22:45:06 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <time.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "cd_function.h"

int			str_wildcard_compare(char *str, char *ptrn);
int			str_is_numeric(char *str);
void		encode_str(char *str);
void		decode_str(char *str);
char		*find_num_left_from_char(char *str, char *c);
int			find_word_right_from_needle(char *c, \
	const char *needle, char **to_write);
const char	*get_rdr_type(int type);
t_rdr_fls	*eject_redirect(char **str, char *c, int rdr_type);
t_rdr_fls	*extract_all_rdrs(char **str);
void		free_rdr_list(t_rdr_fls *item);
void		encode_spec_chars_quotes_str(char *str);
char		**add_str_to_text(char *str, char **text);
char		**expand_wildcard_arr(char *wildcard);
char		**add_text_to_text(char **dest, char **added, int need_free);
void		lvl2_parsing(char *cmd_str, t_cmd *cmd_struct);
void		free_t_cmd(t_cmd *cmd);
void		delete_all_vars(t_vars *start);

void		print_diagram(t_tag *head);
void		print_tree(t_tag *head);
void		print_cmd(t_tag *head);

void	print_text(char **text)
{
	while (*text)
	{
		printf("%s\n", *text);
		text++;
	}	
}

void	print_rdr(t_rdr_fls *item)
{
	char *outs = NULL;
	if (item->out_files)
		outs = ft_anti_split(item->out_files, ", ");
	printf("TYPE: %s, FD: %d, PATH: %s OUT_FILES: [%s]\n",
		get_rdr_type(item->type),
		item->fd,
		item->path,
		outs);
		free(outs);
}

void	print_tcmd(t_cmd *cmd)
{
	int i = 0;
	t_rdr_fls *tmp_rdr;

	printf("\nCOMMAND:\n---\n");
	printf("REDIRECTS:\n");
	tmp_rdr = cmd->redirects;
	while (tmp_rdr)
	{
		printf("%2d:",i++);
		print_rdr(tmp_rdr);
		tmp_rdr = tmp_rdr->next;
	}
	printf("COMMANDS/ARGS:\n");
	i = 0;
	while (cmd->command[i])
	{
		printf("%2d: %s\n",i,  cmd->command[i]);
		i++;
	}
}

int	check_syntax_more(char *string)
{
	int	i;

	i = 0;
	while (ft_isspace(string[i]) == TRUE)
	{
		i += 1;
	}
	if (string[i] == '\0')
	{
		return (-1);
	}
	return (0);
}

void	check_ctrl_d(char *answer)
{
	if (answer == NULL)
	{
		write(1, "\b\bexit\n", 7);
		exit(0);
	}
}

void	minishell_launch(char *answer, t_tag *head)
{
	add_history(answer);
	free(answer);
	// // print_diagram(head);
	// print_tree(head);
	// print_cmd(head);
	// printf("-----------------------------------------\n");
	executor(head);
	remove_tree(head);
}

void	minishell(void)
{
	char	*answer;
	t_tag	*head;

	answer = (char *)1;
	while (answer)
	{
		answer = readline("minishell🧹🗿 ");
		check_ctrl_d(answer);
		if (*answer == '\0' || check_syntax_more(answer) != 0)
		{
			free(answer);
			continue ;
		}
		head = parser(answer);
		if (head == NULL)
		{
			add_history(answer);
			free(answer);
			continue ;
		}
		minishell_launch(answer, head);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*num;

	(void) argv;
	(void) argc;
	envp_init(envp);
	num = ft_itoa(getpid());
	if (num == NULL)
		exit(1);
	g_ms.variables = NULL;
	g_ms.variables = update_vars(g_ms.variables, "$", num);
	free(num);
	signal(SIGINT, signal_new_line);
	signal(SIGQUIT, SIG_IGN);
	minishell();
	return (0);
}
