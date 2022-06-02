/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/03 02:40:41 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

void	tabs_to_spaces_crutch(char *str);

static void	l2p_assign_cmd(char **cmd, char *cmd_str)
{
	*cmd = ft_strdup(cmd_str);
	if (! cmd)
		exit(1);
}

static void	l2p_part2(char ***tmp, char *cmd, t_cmd *cmd_struct, char ***args)
{
	*tmp = ft_split(cmd, ' ');
	if (*tmp == NULL)
	{
		free_rdr_list(cmd_struct->redirects);
		exit(1);
	}
	free(cmd);
	*args = NULL;
	decode_text(*tmp);
	error_empty_command_crutch(&((*tmp)[0]), cmd_struct);
}

void	generate_args(char **tmp, char ***args)
{
	int		i;
	char	*str_tmp0;
	char	*str_tmp1;

	i = 0;
	while (tmp[i])
	{
		str_tmp0 = ft_strdup(tmp[i++]);
		encode_quotes_str(str_tmp0, "*");
		str_tmp1 = open_quotes(str_tmp0);
		free(str_tmp0);
		*args = add_text_to_text(*args, expand_wildcard_arr(str_tmp1), 1);
		decode_text(*args);
	}
}

/*
INPUT:
malloced t_cmd *cmd_struct
*/
void	lvl2_parsing(char *cmd_str, t_cmd *cmd_struct, t_vars *ms_vars)
{
	char	*cmd;
	char	**args;
	char	**tmp;

	tabs_to_spaces_crutch(cmd_str);
	l2p_assign_cmd(&cmd, cmd_str);
	cmd_struct->redirects = extract_all_rdrs(&cmd);
	expand_vars_in_rdrs(cmd_struct->redirects, ms_vars);
	extract_wldcrd_rdrs(cmd_struct->redirects);
	cmd_struct->vars = extract_var_assign(cmd, &cmd, 1, ms_vars);
	expand_vars(&cmd, ms_vars, 1);
	encode_quotes_str(cmd, " ");
	l2p_part2(&tmp, cmd, cmd_struct, &args);
	generate_args(tmp, &args);
	ft_free_text(tmp);
	if (args == NULL)
		args = add_str_to_text(ft_strdup(""), args);
	cmd_struct->command = args;s
}

void	tabs_to_spaces_crutch(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' && ! is_char_in_quotes(str, &str[i]))
			str[i] = ' ';
		i++;
	}
}
