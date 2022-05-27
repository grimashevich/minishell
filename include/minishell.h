/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:59 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/27 13:49:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "wildcard.h"
# include "cd_function.h"
# include "envp.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

enum e_type
{
	END,
	COMMAND,
	CONTAINER
};

enum e_operator
{
	EMPTY,
	AND,
	OR,
	PIPE,
	SEQUENCE
};

enum Rdr_type
{
	WRITE,
	APPEND,
	READ,
	HERE_DOC
};

typedef struct s_rdr_fls
{
	int					type;
	int					fd;
	char				*path;
	char				**out_files;
	struct s_rdr_fls	*next;
}	t_rdr_fls;

typedef struct s_tag
{
	int		type;		// Содержит информацию о типе указатель
	void	*data;		// Содержит указатель либо на команду, либо на контейнер
}	t_tag;

typedef struct s_cont
{
	int			prev_operator;		// Глоабальнй оператор
	int			next_operator;		// Глоабальнй оператор
	t_rdr_fls	*redirects;			// Содержит односвязный список редиректов //TODO добавлено eClown
	t_tag		*tag;
}	t_cont;

typedef struct s_vars
{
	char			*name;
	char			*value;
	int				is_global;
	struct s_vars	*next;
}	t_vars;

typedef struct s_cmd
{
	int				prev_operator;		// Локальный оператор
	int				next_operator;		// Локальный оператор
	char			**command;			// Команда с флагами
	t_cont			*container;			// Проверка на глобальные оператоы перенаправления 
	t_rdr_fls		*redirects;			// Содержит односвязный список редиректов //TODO добавлено eClown
	t_vars			*vars;    			// TODO Добавлено eClown
}	t_cmd;

typedef struct s_pipe
{
	int	prev[2];				// Веременый преведущий канал
	int current[2];				// Веременый текущий кана
}	t_pipe;

typedef struct s_ms
{
	char	**envp;				// Список переменных окружения
	int		exit_code;				// Exit code последней исполненной команды
	// t_tag	*commands;			// Указатель на начало списка текущих команд
	t_vars	*variables;
}   t_ms;

t_ms	g_ms;

void 	ms_error(char *func_name, char *str_error, int errn);
t_tag	*parser(char *line);

t_vars	*update_vars(t_vars *start, char *name, char *new_value);
t_vars	*add_var_first(t_vars *start, t_vars *new_var);
void	executor(t_tag *head);

t_vars *extract_var_assign(char *str, char **out_cmd_wout_assign, int free_old_cmd, t_vars *ms_vars);

#endif // MINISHELL_H

// |--------------------------|
// | Start -> Parser -> Check |
// |--------------------------|

// check the syntax of parentheses
// check the syntax of the operators
// check the quotation mark syntax

//  ~ $ echo 2 (echo 3
//  ~ $ echo 2 )

// bash: syntax error near unexpected token '('
// bash: syntax error near unexpected token ')'

//  ~ $ echo 2 &&
//  ~ $ && echo 2
//  ~ $ echo 2 && && echo 3
//  ~ $ echo 2 || && || echo 3

// bash: syntax error near unexpected token '&&'

//  ~ $ echo 2 "
//  ~ $ echo 2 '

// bash: syntax error near unexpected token '\"'
// bash: syntax error near unexpected token '\''

//  ~ $ > file (echo 1 && echo 2)
//  ~ $ < file (echo 1 && echo 2)
//  ~ $ file > (echo 1 && echo 2)
//  ~ $ file < (echo 1 && echo 2)

// bash: syntax error near unexpected token '('
// bash: syntax error near unexpected token '('
// bash: syntax error near unexpected token '('
// bash: syntax error near unexpected token `('

//  ~ $ (echo 1 && echo 2) file >
//  ~ $ (echo 1 && echo 2) file <

// bash: syntax error near unexpected token 'file'
// bash: syntax error near unexpected token 'file'



// --------------------------------------------------------------



// |---------------------------|
// |         It's work         |
// |---------------------------|


// |---------------------------|
// |          General          |
// |---------------------------|

// echo 1
// echo 1 echo 2
// echo "1 echo 2"
// echo '1 echo 2'

// |---------------------------|
// |         Operator          |
// |---------------------------|

// echo 1 && echo 2
// echo 1 || echo 2
// echo 1 ; echo 2

// |---------------------------|
// |           Pipe            |
// |---------------------------|

// echo 1 | echo 2
// echo 1 | echo 2 | echo 3

// echo 1 > outfile
// echo 1 < infile
// < infile echo 1
// > outfile echo 1

// echo 1 && (echo 2 && echo 3)
// echo 1 || (echo 2 && echo 3)

// (echo 1 && echo 2) && echo 3
// (echo 1 && echo 2) || echo 3

// echo "1 && (echo 2 && echo 3)"
// echo '1 && (echo 2 && echo 3)'

// (echo 1 && echo 2) > outfile
// (echo 1 && echo 2) < infile

// (echo 1 && echo 2) | echo 3
// echo 1 | (echo 2 && echo 3)

// (echo 1 | echo 2) | echo 3

// (echo 1 && echo 2 > outfile) > outfile
// (echo 1 && echo 2 < infile) < infile

// (echo 1 && echo 2 > outfile && echo 3) > outfile

// echo 1 | (echo 2 && echo 3) | echo 4
// echo 1 | (echo 2 && echo 3) > file
// echo 1 | (echo 2 && echo 3) > file | echo 4



// --------------------------------------------------------------



// |---------------------------|
// |        WTF Moment         |
// |---------------------------|
