/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/05/06 20:57:50 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "wildcard/wildcard.h"
# include "eclown/cd_function.h"
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "envp/envp.h"
# include <errno.h>
# include <string.h>

typedef struct s_tag
{
	void			*data;		// Содержит указатель либо на команду, либо на контейнер
	int				type;		// Содержит информацию о типе указатель
}	t_tag;


typedef struct s_ms
{
	char	**envp;				// Список переменных окружения
	int		ms_errno;				// Exit code последней исполненной команды
	t_tag	*commands;			// Указатель на начало списка текущих команд
}   t_ms;
t_ms	g_ms;

void ms_error(char *func_name, char *str_error, int errn);

#endif  /* MINISHELL_H */
