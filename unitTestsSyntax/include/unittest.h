/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:29:05 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 15:24:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTEST_H
# define UNITTEST_H

# include "ft_list.h"
# include <signal.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BOOLEAN
#  define BOOLEAN
#  define TRUE	1
#  define FALSE	0

# endif // BOOLEAN

# define OK			0
# define KO			1
# define ERROR		2
# define TIMEOUT	3

typedef struct s_local
{
	char	*path;
	char	*test;
	t_list	*allocated;
}	t_local;

t_local	g_local;

int		file_open(char *file, int mode);
void	file_dup2_output(int fd);
void	file_close(int fd);

void	check_signal(void);

void	return_status(int status);
void	check_status(void);

void	check_timeout(void);

int		test(void);

char	*get_value_string(char *variable);
int		get_value_int(char *variable);
char	*get_value_output(void);

#endif // UNITTEST_H
