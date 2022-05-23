/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:51 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/10 23:49:33 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>
#include <stdlib.h>
// #include <stdio.h>

static t_list	*get_list(DIR *dir)
{
	t_list			*list;
	t_list			*new;
	char			*data;
	struct dirent	*dp;

	list = NULL;
	dp = readdir(dir);
	while (dp != NULL)
	{
		data = ft_strdup(dp->d_name);
		new = ft_list_new(data);
		if (data == NULL || new == NULL)
		{
			free(data);
			ft_list_remove(new, NULL);
			ft_list_remove_all(&list, free);
			return (NULL);
		}
		ft_list_add_back(&list, new);
		dp = readdir(dir);
	}
	return (list);
}

char	**ls_cwd(char *path)
{
	DIR		*dir;
	char	**strings;
	t_list	*list;

	dir = opendir(path);
	if (dir == NULL)
		return (NULL);
	list = get_list(dir);
	if (list == NULL)
		return (NULL);
	if (closedir(dir))
	{
		ft_list_remove_all(&list, free);
		return (NULL);
	}
	strings = ft_list_to_strings(list);
	ft_list_remove_all(&list, NULL);
	if (strings == NULL)
		return (NULL);
	return (strings);
}

// int		ft_strings_print(char **strings);
// void	ft_strings_remove_all(char ***strings);

// int	main(void)
// {
// 	char	**strings;

// 	strings = ls_cwd("eclown_funcs");
// 	if (strings == NULL)
// 		return (1);
// 	ft_strings_print(strings);
// 	ft_strings_remove_all(&strings);
// 	return (0);
// }
