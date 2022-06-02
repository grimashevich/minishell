/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:40:40 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

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

/*
INPUT:
malloced t_cmd *cmd_struct
*/
void	lvl2_parsing(char *cmd_str, t_cmd *cmd_struct, t_vars *ms_vars)
{
	char	*cmd;
	char	**args;
	char	**tmp;
	int		i;
	char	*str_tmp;

	l2p_assign_cmd(&cmd, cmd_str);
	cmd_struct->redirects = extract_all_rdrs(&cmd);
	expand_vars_in_rdrs(cmd_struct->redirects, ms_vars);
	extract_wldcrd_rdrs(cmd_struct->redirects);
	cmd_struct->vars = extract_var_assign(cmd, &cmd, 1, ms_vars);
	expand_vars(&cmd, ms_vars, 1);
	encode_quotes_str(cmd, " ");
	l2p_part2(&tmp, cmd, cmd_struct, &args);
	i = 0;
	while (tmp[i])
	{
		str_tmp = open_quotes(tmp[i++]);
		args = add_text_to_text(args, expand_wildcard_arr(str_tmp), 1);
	}
	ft_free_text(tmp);
	if (args == NULL)
		args = add_str_to_text(ft_strdup(""), args);
	cmd_struct->command = args;
}

void	free_t_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->command)
		ft_free_text(cmd->command);
	if (cmd->redirects)
		free_rdr_list(cmd->redirects);
	if (cmd->vars)
		delete_all_vars(cmd->vars);
	free(cmd);
}
