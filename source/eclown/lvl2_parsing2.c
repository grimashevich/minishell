/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:32:36 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

char	**split_with_quotes(char *str, char sep, int need_unquote)
{
	char	*str_copy;
	char	*sep_str;
	char	**result;

	str_copy = ft_strdup(str);
	sep_str = ft_strdup(" ");
	if (! str_copy || ! sep_str)
		return (NULL);
	sep_str[0] = sep;
	encode_quotes_str(str_copy, sep_str);
	result = ft_split(str_copy, sep);
	if (result == NULL || result == 0)
		return (NULL);
	decode_text(result);
	if (need_unquote)
		open_quotes_text(result);
	free(str_copy);
	free(sep_str);
	return (result);
}

/*
Determine and return to out_var var assignation.
Doesn't expand variables (i.e. var2=$var1)
1. There is '=' in str
2. First char is letter or '_'
	2.1 Other chars from 1 to '=' is alphanumeric or '_'
3. not
*/
int	is_var_assign(char *str, t_vars **out_var)
{
	int		i;

	*out_var = NULL;
	if (! ft_strchr(str, '='))
		return (0);
	if (! (ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (! (ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	*out_var = malloc(sizeof(t_vars));
	(*out_var)->next = NULL;
	(*out_var)->is_global = 0;
	if (! out_var)
		return (0);
	(*out_var)->name = ft_substr(str, 0, i);
	(*out_var)->value = ft_substr(&str[i + 1], 0, ft_strlen(&str[i + 1]));
	return (1);
}

static	int	iterate_splits(char **splits, t_vars **tmp, t_vars *ms_vars,
		t_vars	**result)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		if (is_var_assign(splits[i], tmp))
		{
			expand_vars(&(*tmp)->value, ms_vars, 0);
			*result = add_var_first(*result, *tmp);
		}
		else
			break ;
		i++;
	}
	return (i);
}

/* IT WORKS AFTER extraxt all redirects
So, in start of the lone we can see only var assignation or command
All text after command will be parametrs of this command */
t_vars	*extract_var_assign(char *str, char **out_cmd_wout_assign,
			int free_old_cmd, t_vars *ms_vars)
{
	char	**splits;
	t_vars	*result;
	t_vars	*tmp;
	int		i;

	splits = split_with_quotes(str, ' ', 0);
	if (! splits)
		return (NULL);
	if (free_old_cmd)
		free(str);
	result = NULL;
	tmp = NULL;
	i = iterate_splits(splits, &tmp, ms_vars, &result);
	if (out_cmd_wout_assign != NULL)
		*out_cmd_wout_assign = empty_str_instead_null(
				ft_anti_split(&(splits[i]), " "));
	ft_free_text(splits);
	return (result);
}

char	*replace_str_in_str(char *haystack, char *start, int len, char *new_str)
{
	int		new_len;
	char	*result;
	int		i;

	if (start < haystack || start + len > haystack + ft_strlen(haystack))
		return (NULL);
	if (new_str == NULL)
		new_str = "";
	new_len = ft_strlen(haystack) - len + ft_strlen(new_str);
	result = malloc(new_len + 1);
	i = 0;
	while (haystack < start)
		result[i++] = *(haystack++);
	haystack += len;
	while (*new_str)
		result[i++] = *(new_str++);
	while (*haystack)
		result[i++] = *(haystack++);
	result[i] = 0;
	return (result);
}
