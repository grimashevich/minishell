/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:38:53 by EClown            #+#    #+#             */
/*   Updated: 2022/06/01 20:09:40 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int	textlen(char **text)
{
	int	result;

	if (text == NULL)
		return (0);
	result = 0;
	while (text[result])
		result++;
	return (result);
}

void	hide_hidden_fles(char **files, char *wildcard)
{
	int	i;

	i = 0;
	if (wildcard[0] == '.')
		return ;
	while (files[i])
	{
		if (files[i][0] == '.')
			files[i][0] = 0;
		i++;
	}
}

/*
Free old str, malloc ans return new str with quotes
*/
char	*put_str_in_quotes(char *str, char quote, int need_free)
{
	char	*result;
	int		strlen;
	int		i;

	strlen = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (strlen + 3));
	if (! result)
		return (NULL);
	i = 0;
	result[0] = quote;
	while (str[i])
	{
		result[i + 1] = str[i];
		i++;
	}
	result[i + 1] = quote;
	result[i + 2] = 0;
	if (need_free)
		free(str);
	return (result);
}

int	is_spec_in_string(char *str)
{
	int	spec_in_str;

	if (! str)
		return (0);
	while (*str)
	{
		spec_in_str = (ft_isspace(*str) || ft_strchr("<>*\"", *str));
		if (spec_in_str)
			return (1);
		str++;
	}
	return (0);
}

char	*escape_single_quotes(char *str, int need_free)
{
	char	**splits;
	char	*result;

	if (str == NULL)
		return (NULL);
	splits = ft_split_new(str, '\'');
	result = ft_anti_split(splits, "'\\''");
	ft_free_text(splits);
	result = put_str_in_quotes(result, '\'', 1);
	if (need_free)
		free(str);
	return (result);
}
