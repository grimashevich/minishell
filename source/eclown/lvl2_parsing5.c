/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:34:48 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

int	str_is_numeric(char *str)
{
	if (str == NULL || *str == 0)
		return (0);
	while (*str)
	{
		if (! ft_isdigit(*(str++)))
			return (0);
	}
	return (1);
}

t_rdr_fls	*create_rdr_fls(char *path, int fd)
{
	t_rdr_fls	*result;

	if (path == NULL && path[0] == 0)
		return (NULL);
	result = malloc(sizeof(t_rdr_fls));
	if (! result)
		return (NULL);
	result->path = path;
	result->out_files = NULL;
	if (! result->path)
	{
		free(result);
		return (NULL);
	}
	result->fd = fd;
	result->next = NULL;
	return (result);
}

t_rdr_fls	*add_last_rdr_file(t_rdr_fls *start, t_rdr_fls *value)
{
	t_rdr_fls	*tmp;

	if (start == NULL && value == NULL)
		return (NULL);
	if (start == NULL)
		return (value);
	if (value == NULL)
		return (start);
	tmp = start;
	while (start->next)
		start = start->next;
	start->next = value;
	return (tmp);
}

void	free_rdr(t_rdr_fls *item)
{
	if (item->path)
		free(item->path);
	if (item->out_files)
		ft_free_text(item->out_files);
	free(item);
}

void	free_rdr_list(t_rdr_fls *item)
{
	t_rdr_fls	*tmp;

	while (item)
	{
		tmp = item->next;
		free_rdr(item);
		item = tmp;
	}
}
