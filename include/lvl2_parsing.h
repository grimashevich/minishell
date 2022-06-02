/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:16:24 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LVL2_PARSING_H
# define LVL2_PARSING_H

# include "minishell.h"

int			is_char_in_quotes(char *str, char *c);
void		encode_quotes_str(char *str, char *char2encode);
char		**add_text_to_text(char **dest, char **added, int need_free);
char		**expand_wildcard_arr(char *wildcard);
void		decode_text(char **text);
void		open_quotes_text(char **text);
char		**add_str_to_text(char *str, char **text);
void		expand_vars(char **cmd, t_vars *vars, int need_unquote);
void		append_envp(char *command);

char		*empty_str_instead_null(char *str);
t_vars		*create_var(char *name, char *value);
t_vars		*add_var_first(t_vars *start, t_vars *new_var);
void		set_var_global(t_vars *start, char *name);
char		*get_var_value(t_vars *start, char *name);
t_vars		*get_var_by_name(t_vars *start, char *name);
void		free_var(t_vars *item);
t_vars		*delete_var(t_vars *start, char *name);
void		delete_all_vars(t_vars *start);
t_vars		*update_vars(t_vars *start, char *name, char *new_value);
char		**split_with_quotes(char *str, char sep, int need_unquote);
int			is_var_assign(char *str, t_vars **out_var);
t_vars		*extract_var_assign(char *str, char **out_cmd_wout_assign,
				int free_old_cmd, t_vars *ms_vars);
char		*replace_str_in_str(char *haystack, char *start, int len,
				char *new_str);
int			get_var_name_len(char *str, char **out_name);
char		*open_quotes_with_free(char *str);
char		*strdup_null_safe(char *str);
void		replace_var_to_exit_code(char **str);
void		expand_vars(char **cmd, t_vars *vars, int need_unquote);
int			str_is_numeric(char *str);
t_rdr_fls	*create_rdr_fls(char *path, int fd);
t_rdr_fls	*add_last_rdr_file(t_rdr_fls *start, t_rdr_fls *value);
void		free_rdr(t_rdr_fls *item);
void		free_rdr_list(t_rdr_fls *item);
char		*del_from_str(char *str, int start, int end);
int			is_char_in_str(char c, char *str);
void		encode_quotes_str(char *str, char *char2encode);
void		encode_spcs_quotes_str(char *str);
char		*encode_spec_chars_quotes_str(char *str);
void		decode_quotes_str(char *str);
char		*find_num_left_from_char(char *str, char *c);
int			find_word_right_from_needle(char *c, const char *needle,
				char **to_write);
char		*get_rdr_type(int type);
int			get_default_fd_by_rdr_type(int type);
void		delete_rdr_from_str(char **str, int start, int end);
int			fd_str_len(char *fd_str);
t_rdr_fls	*eject_redirect(char **str, char *c, int rdr_type);
int			find_next_redirect(char *str, char **out_start_rdr);
t_rdr_fls	*extract_all_rdrs(char **str);
void		decode_text(char **text);
void		open_quotes_text(char **text);
void		extract_wldcrd_rdrs(t_rdr_fls *rdr_start);
void		expand_vars_in_rdrs(t_rdr_fls *rdrs, t_vars *ms_vars);
void		error_empty_command_crutch(char **str, t_cmd *cmd);
void		lvl2_parsing(char *cmd_str, t_cmd *cmd_struct, t_vars *ms_vars);
void		free_t_cmd(t_cmd *cmd);

#endif  /* LVL2_PARSING_H */
