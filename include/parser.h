#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

int		check_syntax(char *line);
int		check_quotation_mark_syntax(char *line);
int		check_syntax_of_parentheses(char *line);
int		check_syntax_of_the_operators(char *line);
int		check_syntax_of_the_redirect(char *line);

void	remove_insignificant_spases(char **line);
void	remove_insignificant_brackets(char **line);
int		count_the_number_of_operators(char *line);
char	*give_a_line_before_operator(char **line, int *prev_op_int);

t_cmd	*get_command(char *line);
t_cont	*get_container(char *line);

int		count_the_number_of_operators(char *line);

void	print_end(void);
void	print_result(char *line);
void	print_this_is_something(char *line, char *type);
void	print_last_character(int character);
void	print_substr(char *line, int start, int lenght);
void	print_remove_insignificant_brackets(char *line);

int		is_this_operator(char **string);
int		skip_single_quotation_mark(char *string);
int		skip_double_quotation_mark(char *string);

int		check_syntax_of_redirect_outfile(char *string);
int		check_error_infile(char *string, int i);
int		check_syntax_of_redirect_infile(char *string);

void	skip_red_all(char **string, int *operator);
int		check_parentheses_all_t(char **string, int *operator);
int		check_parentheses_after_operator(char *string);

int		check_newline(char *string);
int		check_fd_redirect_outfile(char *string);
int		check_fd_redirect_infile(char *string);
int		print_error_redirect_outfile(char *string);

char	*func_join_all(char *line, char *left);
char	*par_for_red(char *line);

#endif // PARSR_H
