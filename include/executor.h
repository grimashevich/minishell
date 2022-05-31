/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:58:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 10:21:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

# define HEREDOC_TMP_FILENAME ".heredoc_tmp"

void	assign_vars_value(t_cmd *command);

void	built_echo(char **command);
void	built_exit(char **code);
void	built_export(char **command);
void	built_pwd(void);
void	built_unset(char **command);

int		here_doc(char *stop_word);
int		built_in(t_cmd *command);
char	*get_file(char *command, char **envp);
int		redirects(t_rdr_fls *redirects);

void	first_cont_pipe(int pipe[2], t_cont *container);
pid_t	last_cont_pipe(int pipe[2], t_cont *container);
void	cont_pipe(int fd[2][2], t_cont *container);

void	first_cmd_pipe(int pipe[2], t_cmd *command);
pid_t	last_cmd_pipe(int pipe[2], t_cmd *command);
void	cmd_pipe(int fd[2][2], t_cmd *command);

void	child_pipe_middle(t_cmd *command, int *process_up_down, int fd[2][2]);
void	child_pipe_last(t_cmd *command, int *process_up_down, int fd[2][2]);
void	child_pipe_first(t_cmd *command, int *process_up_down, int fd[2][2]);

void	juggle_pipes(int arr[2][2]);

int		is_pipe_cmd(t_cmd *command, int *process_up_down, int fd[2][2]);
int		is_variable(t_cmd *command);

void	chil_pipcont_last(t_cont *container, int *process_up_down, int fd[2][2]);
void	chil_pipcont_midd(t_cont *container, int *process_up_down, int fd[2][2]);
void	chil_pipcont_first(t_cont *container, int *process_up_down, int fd[2][2]);

int		is_pipe_cont(t_cont *container, int *process_up_down, int fd[2][2]);

int		need_to_go_back_cont(t_cont *container, int *process_up_down, int fd[2][2]);
int		need_to_go_back(t_cmd *command, int *process_up_down, int fd[2][2]);

void	launch_command(t_cmd *command, int fd[2][2], int *process_up_down);
void	launch_container(t_cont *container, int fd[2][2], int *process_up_down);

#endif // EXECUTOR_H
