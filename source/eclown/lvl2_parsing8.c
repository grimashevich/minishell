/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:37:37 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

void	delete_rdr_from_str(char **str, int start, int end)
{
	char	*tmp;

	tmp = del_from_str(*str, start, end);
	if (! tmp)
		return ;
	free(*str);
	*str = tmp;
}

int	fd_str_len(char *fd_str)
{
	if (fd_str != NULL)
		return (ft_strlen(fd_str));
	return (0);
}

t_rdr_fls	*eject_redirect(char **str, char *c, int rdr_type)
{
	t_rdr_fls	*result;
	char		*fd_str;
	char		*fname;
	int			fd_int;
	int			r_word_len;

	fd_int = get_default_fd_by_rdr_type(rdr_type);
	fd_str = find_num_left_from_char(*str, c);
	if (fd_str)
		fd_int = ft_atoi(fd_str);
	r_word_len = find_word_right_from_needle(c, get_rdr_type(rdr_type), &fname);
	if (r_word_len == -1)
		return (NULL);
	result = create_rdr_fls(fname, fd_int);
	if (! result)
		return (NULL);
	result->type = rdr_type;
	delete_rdr_from_str(str,
		c - *str - fd_str_len(fd_str),
		c - *str + ft_strlen((char *) get_rdr_type(rdr_type)) - 1 + r_word_len);
	if (fd_str)
		free(fd_str);
	return (result);
}

/* 
Search next redirect in str, return type of redirect.
if not found, -1 will be returned
put into *out_start_rdr pointer to first char of found value
 */
int	find_next_redirect(char *str, char **out_start_rdr)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		*out_start_rdr = &str[i];
		if (str[i] == '>')
		{
			if (is_char_in_quotes(str, &str[i]))
				continue ;
			if (str[i + 1] == '>')
				return (1);
			return (0);
		}
		if (str[i] == '<')
		{
			if (is_char_in_quotes(str, &str[i]))
				continue ;
			if (str[i + 1] == '<')
				return (3);
			return (2);
		}
	}
	return (-1);
}

t_rdr_fls	*extract_all_rdrs(char **str)
{
	t_rdr_fls	*result;
	t_rdr_fls	*cur_rdr;
	char		*cur_rdr_start;
	int			cur_rdr_type;

	result = NULL;
	cur_rdr = NULL;
	cur_rdr_start = NULL;
	while (1)
	{
		cur_rdr_type = find_next_redirect(*str, &cur_rdr_start);
		if (cur_rdr_type == -1)
			return (result);
		cur_rdr = eject_redirect(str, cur_rdr_start, cur_rdr_type);
		result = add_last_rdr_file(result, cur_rdr);
	}
}
