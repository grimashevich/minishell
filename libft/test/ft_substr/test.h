/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:04:28 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:39:50 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "libtest.h"

typedef struct s_data
{
	char	*string;
	size_t	start;
	size_t	lenght;
	char	*returned;
	char	*expected;
}	t_data;

t_data	parser(void);
void	remove_all(t_data data);

#endif