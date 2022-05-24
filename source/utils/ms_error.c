/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:19:34 by EClown            #+#    #+#             */
/*   Updated: 2022/05/24 11:59:02 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Set errno to errn value
str_error - is USER ERROR MESSAGE
if str_error is NULL, standart error will be printed
otherwise user error will be printed
*/

void ms_error(char *func_name, char *str_error, int errn)
{
	errno = errn;
	if (str_error)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(func_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str_error, 2);
		ft_putstr_fd("\n", 2);
		return ;
	}	
	ft_putstr_fd("minishell: ", 2);
	perror(func_name);
}