/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:34:59 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/02 22:41:52 by ccamie           ###   ########.fr       */
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

enum e_Rdr_type
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
	int		type;
	void	*data;
}	t_tag;

typedef struct s_cont
{
	int			prev_operator;
	int			next_operator;
	t_rdr_fls	*redirects;
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
	int			prev_operator;
	int			next_operator;
	char		**command;
	t_cont		*container;
	t_rdr_fls	*redirects;
	t_vars		*vars;
	int			is314159265358979323846;
}	t_cmd;

typedef struct s_pipe
{
	int	prev[2];
	int	current[2];
}	t_pipe;

typedef struct s_ms
{
	char	**envp;
	int		exit_code;
	t_vars	*variables;
}	t_ms;

t_ms	g_ms;

void	ms_error(char *func_name, char *str_error, int errn);
t_tag	*parser(char *line);

void	signal_new_line(int num);
t_vars	*update_vars(t_vars *start, char *name, char *new_value);
t_vars	*add_var_first(t_vars *start, t_vars *new_var);
void	executor(t_tag *head);

t_vars	*extract_var_assign(char *str, char **out_cmd_wout_assign, \
	int free_old_cmd, t_vars *ms_vars);

void	remove_tree(t_tag *head);

#endif // MINISHELL_H
