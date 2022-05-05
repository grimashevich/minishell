/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:28:44 by EClown            #+#    #+#             */
/*   Updated: 2022/04/11 23:54:44 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int compare_closed_str(char *str, char *ptrn)
{
	int		str_len;
	int		ptrn_len;
	char	**substrs;
	int		result;
	int		i;

	i = 0;
	result = 1;
	str_len = ft_strlen(str);
	ptrn_len = ft_strlen(ptrn);
	if (ptrn_len == 1 && ptrn[0] == '*')
		return (1);
	substrs = ft_split(ptrn, '*');
	if (! substrs)
		return (-1);
	while (substrs[i])
	{
		str = ft_strnstr(str, substrs[i], ft_strlen(str));
		if (str == NULL && result--)
			break;
		str += ft_strlen(substrs[i++]);
	}
	ft_free_text(substrs);
	return (result);
}

int compare_start(char *str, char *ptrn)
{
	char	**ptrn_list;
	int		result;

	result = -1;
	if (ptrn[0] == '*')
		return (0);
	ptrn_list = ft_split(ptrn, '*');
	if (! ptrn_list)
		return (-1);
	if (ft_strnstr(str, ptrn_list[0], ft_strlen(ptrn_list[0])))
		result = ft_strlen(ptrn_list[0]);
	ft_free_text(ptrn_list);
	return (result);
}

static int cmp_str_from_end(char *str1, char* str2, int len)
{
	int	i;
	int	j;
	
	i = ft_strlen(str1) - 1;	
	j = ft_strlen(str2) - 1;
	if (len > i + 1 || len > j + 1 || len < 1)
		return (0);
	if (i == -1 && i == j)
		return (1);
	while (len > 0)
	{
		if (str1[i--] != str2[j--])
			return (0);
		len--;
	}
	return (1);
}

int compare_end(char *str, char *ptrn)
{
	char	**ptrn_list;
	char	**ptrn_tmp;
	int		result;
	int		ptrn_len;


	result = -1;
	ptrn_len = ft_strlen(ptrn);
	if (ptrn[ptrn_len - 1] == '*')
		return (0);
	ptrn_list = ft_split(ptrn, '*');
	if (! ptrn_list)
		return (-1);
	ptrn_tmp = ptrn_list;
	while (*(ptrn_tmp + 1) != NULL)
		ptrn_tmp++;
	if (cmp_str_from_end(str, *ptrn_tmp, ft_strlen(*ptrn_tmp)))
		result = ft_strlen(*ptrn_tmp);
	ft_free_text(ptrn_list);
	return (result);
}
