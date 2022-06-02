/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:27:07 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 23:45:22 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lvl2_parsing.h"

/*
Return new string with deleted chars from start index to end index (included)
*/
char	*del_from_str(char *str, int start, int end)
{
	int		strlen;
	char	*result;
	int		i;
	int		j;

	strlen = ft_strlen(str);
	if (str == NULL || strlen - 1 < end - start || end < 0 || start < 0)
		return (NULL);
	result = malloc(sizeof(char) * (strlen - (end - start)));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i < start || i > end)
			result[j++] = str[i];
		i++;
	}
	result[j] = 0;
	return (result);
}

int	is_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (*(str++) == c)
			return (1);
	}
	return (0);
}

/*
Replace char witch contains in char2encode to its negative
variant if it in quotes
*/
void	encode_quotes_str(char *str, char *char2encode)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_char_in_str(str[i], char2encode)
			&& is_char_in_quotes(str, &str[i]))
			str[i] *= -1;
		i++;
	}
}

void	encode_spcs_quotes_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) && is_char_in_quotes(str, &str[i]))
			str[i] *= -1;
		i++;
	}
}

/*
Nothing to be malloced
Returned tha same pointer
*/
char	*encode_spec_chars_quotes_str(char *str)
{
	int	i;
	int	searched_chars;

	i = 0;
	while (str[i])
	{
		searched_chars = (ft_isspace(str[i]) || str[i] == '*');
		searched_chars = (searched_chars && is_char_in_quotes(str, &str[i]));
		if (searched_chars)
			str[i] *= -1;
		i++;
	}
	return (str);
}
