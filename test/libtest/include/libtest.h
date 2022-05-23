/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:35:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

# include "minishell.h"
# include "parser.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER 1024
# define TEST_TIMEOUT	2
# define TEST_ERROR		3

char	*g_input;
char	*g_output_file;

char			*get_output(void);

int				get_value_int(char *variable);
long			get_value_long(char *variable);
size_t			get_value_size_t(char *variable);
unsigned int	get_value_unsigned_int(char *variable);
char			*get_value(char *variable);

#endif // LIBTEST_H
