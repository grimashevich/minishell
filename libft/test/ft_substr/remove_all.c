/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:30:57 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/11 18:40:06 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	remove_all(t_data data)
{
	free(data.string);
	free(data.returned);
	free(data.expected);
}
