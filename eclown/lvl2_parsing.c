/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:04:22 by EClown            #+#    #+#             */
/*   Updated: 2022/05/12 22:01:19 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"


t_rdr_fls	*create_rdr_fls(char *path, int fd)
{
	t_rdr_fls	*result;

	if (path == NULL && path[0] == 0)
		return (NULL);
	result = malloc(sizeof(t_rdr_fls));
	if (! result)
		return (NULL);
	result->path = ft_strdup(path);
	if (! result->path)
	{
		free(result);
		return (NULL);
	}
	result->fd = fd;
	result->next = NULL;
	return (result);
}

void add_last_rdr_file(t_rdr_fls *start, t_rdr_fls *value)
{
	if (start == NULL)
		return ;
	while (start->next)
		start = start->next;
	start->next = value;
}

/*
return new string with deleted chars from start index to end index (included)
*/
char* del_from_str(char *str, int start, int end)
{
	int		strlen;
	char	*result;
	int		i;
	int		j;

	strlen = ft_strlen(str);
	if (str == NULL || strlen - 1 < end - start || end < 0 || start < 0)
		return (NULL);
	result = malloc(sizeof(char) * (strlen - (end - start)));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i < start || i > end)
			result[j++] = str[i];
		i++;
	}
	result[j] = 0;
	return (result);
}

/* 
Fill
arr[0] - for input
arr[0] for output
if redirectes found ins str, the function will change given string.
	It will remove resirectes from string.

EXAMPLE:
	INPUT str = "< in.txt echo 1 > out.txt"
	arr[0] = "in.txt"
	arr[1] = "out.txt"
	str = "echo 1"
 */

/* void	extract_redirects(char *str, t_cmd *cmd)
{
	char	**result;

	
}
 */

/* void parse_lvl2(t_cmd *cmd, char *cmd_str)
{
	char	*str;
	char	tmp;
	char	**redirects;

	str = ft_strdup(cmd_str);
	extract_redirects(str, cmd);
	tmp = str;
	str = ft_strtrim(str, " \t\n");
	free(tmp);
	
} */