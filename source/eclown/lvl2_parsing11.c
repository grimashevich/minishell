/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 02:31:58 by EClown            #+#    #+#             */
/*   Updated: 2022/06/03 02:45:23 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

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
