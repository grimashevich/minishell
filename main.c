/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:45:25 by EClown            #+#    #+#             */
/*   Updated: 2022/05/19 19:44:58 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include <time.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "eclown/cd_function.h"


int	str_wildcard_compare(char *str, char *ptrn);
int str_is_numeric(char *str);
void encode_str(char *str);
void decode_str(char *str);
char *find_num_left_from_char(char *str, char *c);
int find_word_right_from_needle(char *c, const char *needle, char **to_write);
const char *get_rdr_type(int type);
t_rdr_fls *eject_redirect(char **str, char *c, int rdr_type);
t_rdr_fls *extract_all_rdrs(char **str);
void free_rdr_list(t_rdr_fls *item);
void encode_spec_chars_quotes_str(char *str);
char **add_str_to_text(char *str, char **text);
char	**expand_wildcard_arr(char *wildcard);
char	**add_text_to_text(char **dest, char **added, int need_free);

void print_text(char **text)
{
	while (*text)
	{
		printf("%s\n", *text);
		text++;
	}	
}


void print_rdr(t_rdr_fls *item)
{
	printf("TYPE: %s, FD: %d, PATH: %s\n", get_rdr_type(item->type), item->fd, item->path);
}



int	main(int argc, char **argv, char **envp)
{
	(void) argv;
	(void) argc;
	(void) envp;


/* // TEST CASE
	
	char *answer = malloc(256);

	char **text = NULL;

	while (answer)
	{
		answer = readline("Enter str: ");
		add_history(answer);
		text = add_to_text(answer, text);
		print_text(text);
		printf("\n\n");
		//free(answer);
	}
	ft_free_text(text); */

// TEST CASE  char	**expand_wildcard_arr(char *wildcard)
	
	char *answer = malloc(256);

	char **text = NULL;
	while (answer)
	{
		answer = readline("Enter str: ");
		add_history(answer);
		text = expand_wildcard_arr(answer);
		print_text(text);
		printf("\n\n");
		free(answer);
		ft_free_text(text);
	}


/* // CASE extract_all_rdrs
	//char *answer = malloc(256);
	t_rdr_fls	*rdr;

	//answer = readline("Enter str: "); 
	//char *answer = ft_strdup("ehco abc <<hereDOC >out.txt <infile 2>../dir1/error.log 3>number3file -param1 param2");
	char *answer = ft_strdup("ehco abc -param1 <infile \"1>param2\" >\"out file\" param3 3>fd3-2fl");
	//answer = ft_strdup("ehco abc 2>error.log next_cmd");
	//add_history(answer);
	rdr = extract_all_rdrs(&answer);
	while (rdr)
	{
		print_rdr(rdr);
		rdr = rdr->next;
	}
	
	printf("\n---\n%s\n", answer);
	//int *result = find_num_left_from_char(answer, ft_strnstr(answer, "<", ft_strlen(answer)));
	free(answer);
	free_rdr_list(rdr);
 */
	
/* // TEST CASE FOR expand_wildcard_in_str
	char *answer = malloc(256);

	while (answer)
	{
	
		answer = readline("Enter command with wildcard: ");
		add_history(answer);
		char *files = expand_wildcard_in_str(answer);
		free(answer);
		printf("---\n=> %s\n\n", files);
		free(files);
	} */

/* 	// TEST CASE FOR change_directory
	char *answer = malloc(256);
	char *cwd;

	envp_init(envp);
	while (1)
	{
		printf("\tPWD from envp:\t\t%s\n", envp_get_value("PWD"));
		printf("\tOLDPWD from envp:\t%s\n\n", envp_get_value("OLDPWD"));
		cwd =  getcwd(NULL, MAX_PATH_LEN);
		printf("\tPWD from get_cwd:\t%s\n",cwd);
		free(cwd);
		answer = readline("\nEnter new dir for cd command: ");
		change_direcory(answer);
		free(answer);
		printf("\n\n");
	} */
	
/* // TEST CASE FOR symb_count_before_char
	
	char *answer = malloc(256);

	while (answer)
	{
		answer = readline("Enter str for symb_count_before_char: ");
		add_history(answer);
		char c = '"';
		char *char_before = ft_strrchr(answer, '*');
		int res  = symb_count_before_char(c, answer, char_before);
		free(answer);
			printf("---\n=> %d\n\n", res);
	} */

/* // TEST CASE FOR symb_count_after_char
	
	char *answer = malloc(256);

	while (answer)
	{
		answer = readline("Enter str for symb_count_after_char: ");
		add_history(answer);
		char c = '"';
		char *char_after = ft_strrchr(answer, '*');
		int res  = symb_count_after_char(c, char_after);
		free(answer);
			printf("---\n=> %d\n\n", res);
	} */

/* // TEST CASE FOR encode_spec_chars_quotes_str
	
	char *answer = malloc(256);

	while (answer)
	{
		answer = readline("Enter str for encode: ");
		add_history(answer);
		encode_spec_chars_quotes_str(answer);
		printf("ENCODED ANSWER: %s\n", answer);
		free(answer);
	} */

/* // TEST CASE FOR open_quotes
	
	char *answer = malloc(256);

	while (answer)
	{
		answer = readline("Enter str for open quotes: ");
		add_history(answer);
		char *result = open_quotes(answer);
		free(answer);
			printf("---\n=> %s\n\n", result);
		free(result);
	} */

/* // TEST CASE FOR remove_quotes
	
	char *answer = malloc(256);

	while (answer)
	{
		answer = readline("Enter str for remove quotes: ");
		add_history(answer);
		char *result = remove_quotes(answer);
		free(answer);
			printf("---\n=> %s\n\n", result);
		free(result);
	} */

/* // TEST CASE FOR is_char_in_quotes
	
	char *answer = malloc(256);

	while (answer)
	{
		answer = readline("Enter str for test is_char_in_quotes(): ");
		add_history(answer);
		int result = is_char_in_quotes(answer, ft_strchr(answer, '*'));
		free(answer);
		if (result)
			printf("---\n=> TRUE\n\n");
		else
			printf("---\n=> FALSE\n\n");

	} */

/* // TEST CASE FOR 	char *expand_wildcard_cwd(char *wildcard)

	char * answer = malloc(256);
	while (answer)
	{
	
		answer = readline("Enter wildcard: ");
		add_history(answer);
		char *files = expand_wildcard_cwd(answer);
		free(answer);
		printf("\n%s\n", files);
		free(files);
	} */
	
/* // TEST CASE FOR pre_str_wildcard_compare
	
	char *answer = malloc(256);

	int result = pre_str_wildcard_compare("t*est", "*t'*'*");
		free(answer);
		if (result)
			printf("---\n=> TRUE\n\n");
		else
			printf("---\n=> FALSE\n\n"); */
 
/* // TEST CASE FOR 	char **apply_wildcard(char *pattern, char** text)

	char **text = malloc(sizeof(char **) * 3);
	int i = 0;

	text[i++] = ft_strdup("str one");
	text[i++] = ft_strdup("str two");
	text[i++] = NULL;
	
	char** text2 = apply_wildcard("*", text);
	ft_free_text(text);
	print_text(text2);
	ft_free_text(text2);
*/
	
	return (0);
}
 