/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:31 by EClown            #+#    #+#             */
/*   Updated: 2022/06/03 00:02:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int		compare_start(char *str, char *ptrn);
int		compare_end(char *str, char *ptrn);
int		compare_closed_str(char *str, char *ptrn);
char	*str_join_3(char *str1, char *str2, char *str3);
char	*encode_spec_chars_quotes_str(char *str);

int	str_wildcard_compare_2(char **closed_ptrn, char *closed_str, int result)
{
	if (! *closed_ptrn)
	{
		free(closed_str);
		return (0);
	}
	result = compare_closed_str(closed_str, *closed_ptrn);
	free(closed_str);
	free(*closed_ptrn);
	return (result);
}

int	str_wildcard_compare(char *str, char *ptrn)
{
	int		star_cut;
	int		end_cut;
	char	*closed_str;
	char	*closed_ptrn;
	int		result;

	if (find_first_char(ptrn, '*') == -1)
	{
		if (ft_strncmp(str, ptrn, ft_max_int(ft_strlen(str),
					ft_strlen(ptrn))) == 0)
			return (1);
		return (0);
	}
	star_cut = compare_start(str, ptrn);
	end_cut = -1;
	if (star_cut != -1)
		end_cut = compare_end(str, ptrn);
	if (end_cut == -1)
		return (0);
	closed_str = ec_str_copy(str, star_cut, end_cut);
	if (! closed_str)
		return (0);
	closed_ptrn = ec_str_copy(ptrn, star_cut, end_cut);
	result = 0;
	return (str_wildcard_compare_2(&closed_ptrn, closed_str, result));
}

static void	replace_sym_to_minus_q(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && is_char_in_quotes(str, &(str[i])))
			str[i] = -1 * c;
		i++;
	}
}

static void	replace_sym_to_minus(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = -1 * c;
		i++;
	}
}

int	pre_str_wildcard_compare(char *str, char *ptrn)
{
	char	*new_str;
	char	*new_ptrn;
	char	*tmp;
	int		result;

	new_ptrn = ft_strdup(ptrn);
	if (! new_ptrn)
		return (0);
	replace_sym_to_minus_q(new_ptrn, '*');
	tmp = new_ptrn;
	new_ptrn = open_quotes(tmp);
	free(tmp);
	if (! new_ptrn)
		return (0);
	new_str = ft_strdup(str);
	if (! new_str)
	{
		free (new_ptrn);
		return (0);
	}
	replace_sym_to_minus(new_str, '*');
	result = str_wildcard_compare(new_str, new_ptrn);
	free(new_str);
	free(new_ptrn);
	return (result);
}
