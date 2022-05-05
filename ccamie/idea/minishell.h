/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:59 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/05 21:18:16 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>	// ban

enum e_boolean
{
	FALSE,
	TRUE
};

enum e_type
{
	COMMAND,
	CONTAINER
};

typedef struct s_tag
{
	void			*data;		// Содержит указатель либо на команду, либо на контейнер
	int				type;		// Содержит информацию о типе указатель
	struct s_tag	*next;		// Содержит указатель на следующий элемент
}	t_tag;

typedef struct s_cont
{
	int		prev_operator;		// Глоабальнй оператор
	int		next_operator;		// Глоабальнй оператор
	char	*infile;			// Путь до файла						|
	char	*outfile;			// Путь до файла						|
	int		append_outfile;		// Создать или добававить в файл		|	отдельная структура???
	int		isheredoc;			// Создать временый файл				|
	int		infd;				// Всегда dup2
	int		outfd;				// Всегда dup2
	t_tag	*tag;
}	t_cont;

typedef struct s_cmd
{
	int		prev_operator;		// Локальный оператор
	int		next_operator;		// Локальный оператор
	char	*infile;			// Путь до файла						|
	char	*outfile;			// Путь до файла						|
	int		append_outfile;		// Создать или добававить в файл		|	отдельная структура???
	int		isheredoc;			// Создать временый файл				|
	char	**command;			// Команда с флагами
	t_cont	*container;			// Проверка на глобальные оператоы перенаправления 
}	t_cmd;

typedef struct s_pipe
{
	int	prev[2];				// Веременый преведущий канал
	int current[2];				// Веременый текущий канал
}	t_pipe;

// ban
// ban
// ban
// ban
// ban	- это значит: что это надо удалить!!!!!!!! 	// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban
// ban

typedef struct s_ms
{
	char	**envp;				// Список переменных окружения
	int		errno;				// Exit code последней исполненной команды
	t_tag	*commands;			// Указатель на начало списка текущих команд
}   t_ms;

t_ms	g_ms;

t_tag	*tag_init(void *data, int type);	// struct
t_tag	*tag_last(t_tag *head);	// struct
t_tag	*tag_add_back(t_tag **head, t_tag *new);	// struct

int		ft_isspace(int character);	// ban
size_t	ft_strlen(char *string);	// ban
size_t	ft_strlcpy(char *from, char *to, size_t lenght);	// ban
char	*ft_substr(char *string, size_t start, size_t length);	// ban
int		ft_strcmp(char *one, char *two);	// ban
int		ft_strncmp(char *one, char *two, size_t length);	// ban

#endif // MINISHELL_H




// echo 1 && (echo 2 || echo 3) && echo 4

//   tag -> tag -> tag -> NULL
//    |      |      |
//   echo 1 con   echo 4
//           |
//          tag -> tag -> NULL
//           |      |
//         echo 1 echo 2






































// --------------------------------------------------------------



// (echo 1 | echo 2) > file

//   tag -> tag -> NULL
//    |      |
//   con   "out"
//    |
//   tag -> tag -> NULL
//    |      |
//  echo 1 echo 2

// iscase = CONTAINER;        // prev_operator = NULL
// data = container;    ->    // next_operator = ">"
// next = tag;                // 
                              // 
							  //

// iscase = FILE;
// data = "out"
// next = NULL;

// iscase = COMMAND;          // prev_operator = NULL
// data = command;      ->    // next_operator = "|"
// next = tag;                // command[0] = "echo"
                              // command[1] = "1"
                              // command[2] = NULL

// iscase = COMMAND;          // prev_operator = "|"
// data = command;      ->    // next_operator = NULL
// next = NULL;               // command[0] = "echo"
                              // command[1] = "2"
                              // command[2] = NULL



// --------------------------------------------------------------


// echo 1 | (echo 2 | echo 3) > file

//   tag -> tag -> tag -> NULL
//    |      |      |
//   echo 1 con   "out"
//           |
//          tag -> tag -> NULL
//           |      |
//         echo 1 echo 2

// iscase = COMMAND;          // prev_operator = NULL
// data = command;      ->    // next_operator = "|"
// next = tag;                // command[0] = "echo"
                              // command[1] = "1"
                              // command[2] = NULL

// iscase = CONTAINER;        // prev_operator = "|"
// data = container;    ->    // next_operator = ">"
// next = tag;                // 
                              // 
							  //

// iscase = FILE;
// data = "out"
// next = NULL;

// iscase = COMMAND;          // prev_operator = NULL
// data = command;      ->    // next_operator = "|"
// next = tag;                // command[0] = "echo"
                              // command[1] = "2"
                              // command[2] = NULL
							  // container <-

// iscase = COMMAND;          // prev_operator = "|"
// data = command;      ->    // next_operator = NULL
// next = NULL;               // command[0] = "echo"
                              // command[1] = "3"
                              // command[2] = NULL



// --------------------------------------------------------------



// echo 1 | (echo 2 && echo 3) > file



// --------------------------------------------------------------



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

// (echo 1 | echo 2) | echo 3
// (echo 1) - Он должен наследовать 2 канала на запись?
