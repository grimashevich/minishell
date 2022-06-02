/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:34:11 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

typedef struct s_ev_str
{
	char	*tmp;
	char	*var_name;
	char	*var_value;
}	t_ev_str;

static void	ev_get_var_value(char *var_name, char **var_value,
	t_vars *vars, int need_unquote)
{
	if (envp_get_value(var_name))
		*var_value = strdup_null_safe(envp_get_value(var_name));
	else
		*var_value = strdup_null_safe(get_var_value(vars, var_name));
	if (need_unquote)
		*var_value = open_quotes_with_free(*var_value);
}

static char	*ev_get_new_free_old(char *old, char *new)
{
	free(old);
	return (new);
}

static void	update_tmp_and_free(char **tmp, char **cmd,
		char **v_name, char **v_value)
{
	*tmp = ft_strchr(*cmd + ft_strlen(*v_value), '$');
	free(*v_name);
	free(*v_value);
	*v_name = NULL;
	*v_value = NULL;
}

static void	update_tmp_and_free2(char **var_name, char **tmp)
{
	if (*var_name)
		free(*var_name);
	*var_name = NULL;
	*tmp = ft_strchr(++(*tmp), '$');
}

void	expand_vars(char **cmd, t_vars *vars, int need_unquote)
{
	int			name_len;
	t_ev_str	s;

	replace_var_to_exit_code(cmd);
	s.tmp = ft_strchr(*cmd, '$');
	while (s.tmp)
	{
		if (ft_isspace(*(s.tmp + 1)) || *(s.tmp + 1) == '\0')
		{
			if (*(s.tmp + 1) == '\0')
				break ;
			s.tmp++;
			continue ;
		}
		name_len = get_var_name_len(s.tmp, &s.var_name);
		if (name_len > 0 && is_char_in_quotes(*cmd, s.tmp) != '\'')
		{			
			ev_get_var_value(s.var_name, &s.var_value, vars, need_unquote);
			*cmd = ev_get_new_free_old(*cmd, replace_str_in_str(*cmd, s.tmp,
						name_len, s.var_value));
			update_tmp_and_free(&s.tmp, cmd, &s.var_name, &s.var_value);
			continue ;
		}
		update_tmp_and_free2(&s.var_name, &s.tmp);
	}
}
