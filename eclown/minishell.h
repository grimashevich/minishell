/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/05/04 19:31:42 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TMP_FILE_NAME ".tmp_file"
# define LLI_MIN "9223372036854775808"
# define LLI_MAX "9223372036854775807"
# define MAX_PATH_LEN 4096

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft/libft.h"

typedef struct s_str
{
	char			*value;
	struct s_str	*next;
}	t_str;

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_str	*next;
}	t_dict;

enum Exec_condition
{
	ANY_CASE,
	ERROR,
	SUCCESS
};

typedef struct s_cmd
{
	int				exec_condition;	// Условие выполнения в зависимости от результат предыдущей команды 'A' (Any case), 'E' (error) 'S' (succes)
	int				in_fd;			// fd для входящего потока
	int				out_fd;			// fd для исходящего потока
	int				isbroken;		// 1 если команда задана не верно, иначе 0		???
	char			*error_text;	// Если is_broken == 1, содержит текст ошибки для вывода	???
	int				isfunc;			// 1 если команда является внутренний функций, иначе 0
	char			**command;		// Массив. 0-й аргумент путь до файла (имя функции), остальные элементы - аргументы.
	struct s_cmd	*next;			// Указатель на следующий элемент (по горизонтали)
	struct s_cmd	*child;			// Указатель на потомка (NULL по умолчанию). Если  NULL, то это команда.
}	t_cmd;

typedef struct s_cmd_cntr
{
	t_cmd				*first_command;
	int					exec_condition;	// Условие выполнения в зависимости от результат предыдущей команды 'A' (Any case), 'E' (error) 'S' (succes)
	struct s_cmd_cntr	*children;
	t_list				*cntrs;

}	t_cmd_c;

typedef struct s_ms
{
	char	**envp;
	t_cmd	*commands;		// Указатель на начало списка текущих команд
	t_str	*funcs;			// Список валидных функций minishell
	t_dict	*vars;			// Список переменных типа  $var
	int		exit_code;		// Exit code последней исполненной команды
}   t_ms;

typedef struct s_2int2
{
	int	s[2];
	int	p[2];
}	t_2int2;


char	**apply_wildcard(char *pattern, char** text);
int		total_compare(char *str, char *ptrn);
int		get_lines_count(char **text);
int		find_first_char(char *str, char c);
char	*ec_str_copy(char *str, int cut_start, int cut_end);
char	**ls_cwd(char *path);
char	*ft_anti_split(char **strings, char *separator);
char	*expand_wildcard_cwd(char *wildcard);
char	**ft_list_to_strings(t_list *list);
void	ft_list_remove_all(t_list **list, void (*del)(void *));
char	*expand_wildcard_in_str(char *str);
int		is_char_in_quotes(char *str, char *c);
char	*remove_quotes(char *str);
char	*open_quotes(char *str);
int		symb_count_before_char(char c, char *str, char *before);
int		symb_count_after_char(char c, char *after);
int		pre_str_wildcard_compare(char *str, char *ptrn);


void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
void	ft_list_remove_all(t_list **list, void (*del)(void *));
int		ft_list_remove_current(t_list **list, t_list *current, void (*del)(void *));
void	ft_list_remove(t_list *list, void (*del)(void *));
size_t	ft_list_get_count(t_list *list);
t_list	*ft_list_get_last(t_list *list);
t_list	*ft_list_get_prev(t_list *list, t_list *current);
void	ft_list_iter(t_list *list, void (*fun)(void *));
t_list	*ft_list_map(t_list *list, void *(*fun)(void *), void (*del)(void *));
t_list	*ft_list_new(void *content);
char	**ft_list_to_strings(t_list *list);

t_list	*ft_strings_to_list(char **strings);

void	ft_strcpy(const char *from, char *to);

/* 

РЕКУРСИВНЫЙ ПАРСЕР 1 УР.

s_cmd	*parser_lvl1(char *str, int start, int end)

((cmd1 && (cmd2 param1 param2 | cmd 3) || cmd4 param1) | ((((cmd5) | cmd 6))))
выделить сущности между &&, || и |

 вернет
 cont	-	-	-	cmd5 | cmd6
  |
  |
  |
  |
 cmd1	-	cont	-	cmd4
			  |
			  |
			  |
			  |
			  cmd2	-	cmd3
 
 
 ПАРСЕР 2 УР.
 Парсит сущности, которые создал парсер 1 ур.
 	Фактически рабзирает каждую конкретную команду на саму команду и параметры.
	Преобразовывает переменные в их значения
	Разбирает кавычки

 char	**parser_lvl2(char *str);

 */

#endif  /* MINISHELL_H */
