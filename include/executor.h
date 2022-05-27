/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:58:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/27 13:47:12 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

void	assign_vars_value(t_cmd *command);

void	built_echo(char **command);
void	built_exit(char **code);
void	built_export(char **command);
void	built_pwd(void);
void	built_unset(char **command);

#endif // EXECUTOR_H
