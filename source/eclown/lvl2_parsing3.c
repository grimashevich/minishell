/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:44:48 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

/*
return var name lenght includeing first '$' symbol
write to *out_name var name without first '$' symbol
*str - is pointer to first '$' in str
 */
int	get_var_name_len(char *str, char **out_name)
{
	int	i;

	if (ft_isspace(str[1]) || ft_isdigit(str[1]))
	{
		*out_name = NULL;
		return (0);
	}
	if (str[1] == '$')
	{
		*out_name = ft_strdup("$");
		return (2);
	}
	i = 1;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	*out_name = malloc(i);
	if (! *out_name)
		ms_error("get_var_name_len", "malloc error", errno);
	ft_strlcpy(str + 1, *out_name, i);
	return (i);
}

char	*open_quotes_with_free(char *str)
{
	char	*new_str;

	if (! str)
		return (NULL);
	new_str = open_quotes(str);
	free(str);
	return (new_str);
}

char	*strdup_null_safe(char *str)
{
	if (! str)
		return (ft_strdup(""));
	return (ft_strdup(str));
}

void	replace_var_to_exit_code(char **str)
{
	char	*ec_var;
	char	*tmp;
	char	*str_exit_code;

	ec_var = ft_strnstr(*str, "$?", ft_strlen(*str));
	while (ec_var)
	{
		str_exit_code = ft_itoa(g_ms.exit_code);
		if (! str_exit_code)
			exit(1);
		tmp = replace_str_in_str(*str, ec_var, 2, str_exit_code);
		if (! tmp)
			exit(1);
		free(str_exit_code);
		free(*str);
		*str = tmp;
		ec_var = ft_strnstr(*str, "$?", ft_strlen(*str));
	}
}
