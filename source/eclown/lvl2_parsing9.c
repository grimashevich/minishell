/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:39:09 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

void	decode_text(char **text)
{
	while (*text)
		decode_quotes_str(*(text++));
}

void	open_quotes_text(char **text)
{
	char	*tmp;

	while (*text)
	{
		tmp = open_quotes(*text);
		if (! tmp)
			ms_error("open_quotes_text", "malloc error", 1);
		free(*text);
		*text = tmp;
		text++;
	}
}

void	extract_wldcrd_rdrs(t_rdr_fls *rdr_start)
{
	char		**splits;
	int			i;

	while (rdr_start)
	{
		encode_spcs_quotes_str(rdr_start->path);
		splits = ft_split(rdr_start->path, ' ');
		if (! splits)
			return ;
		decode_text(splits);
		i = 0;
		while (splits[i])
		{
			rdr_start->out_files = add_text_to_text(
					rdr_start->out_files,
					expand_wildcard_arr(open_quotes(splits[i++])),
					1);
		}
		ft_free_text(splits);
		decode_quotes_str(rdr_start->path);
		rdr_start = rdr_start->next;
	}
}

void	expand_vars_in_rdrs(t_rdr_fls *rdrs, t_vars *ms_vars)
{
	while (rdrs)
	{
		expand_vars(&(rdrs->path), ms_vars, 1);
		rdrs = rdrs->next;
	}
}

void	error_empty_command_crutch(char **str, t_cmd *cmd)
{
	char	*tmp;

	if (*str && (ft_strchr(*str, '\'') || ft_strchr(*str, '"')))
	{
		tmp = open_quotes(*str);
		if (tmp[0] == '\0')
			cmd->is314159265358979323846 = 1;
		else
			cmd->is314159265358979323846 = 0;
		free(tmp);
	}
	else
		cmd->is314159265358979323846 = 0;
}
