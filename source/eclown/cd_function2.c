/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:45:00 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 16:45:27 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_function.h"

int	ms_error_free_return(char *msg, char *to_free)
{
	if (to_free)
		free(to_free);
	ms_error(msg, NULL, errno);
	return (errno);
}
