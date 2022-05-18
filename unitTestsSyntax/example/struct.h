/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:59:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/18 16:59:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "unittest.h"

typedef struct s_data
{
	int		id;
	char	*string;
	int		returned;
	int		expected_returned;
	char	*output;
	char	*expected_output;
	int		isreturned;
	int		isoutput;
}	t_data;

t_data	g_data;

#endif // STRUCT_H
