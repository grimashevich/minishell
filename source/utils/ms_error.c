/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:19:34 by EClown            #+#    #+#             */
/*   Updated: 2022/05/29 19:31:49 by EClown           ###   ########.fr       */
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
	g_ms.exit_code = errn;
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