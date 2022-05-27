/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:58:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/27 00:39:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

void	assign_vars_value(t_cmd *command);

void	built_echo(char **command);
void	built_exit(char **code);
void	built_unset(char **command);

t_vars	*update_vars(t_vars *start, char *name, char *new_value);
t_vars	*add_var_first(t_vars *start, t_vars *new_var);

#endif // EXECUTOR_H
