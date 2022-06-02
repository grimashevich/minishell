/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:46:40 by EClown            #+#    #+#             */
/*   Updated: 2022/06/03 02:42:16 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

char	**expand_wildcard_arr(char *wildcard);
char	**quote_str_with_spec(char **text);
void	encode_quotes_str(char *str, char *char2encode);

char	**encode_file_names(char **text)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (text[i])
	{
		while (text[i][j])
		{
			if (text[i][j] == '*')
				text[i][j] *= -1;
			j++;
		}
		i++;
		j = 0;
	}
	return (text);
}

char	**apply_wildcard(char *pattern, char **text)
{
	char	**arr;
	char	**arr2;
	int		i;

	arr = malloc(sizeof(char **) * (get_lines_count(text) + 1));
	if (! arr)
		return (NULL);
	i = 0;
	while (*text)
	{
		if (**text != 0 && pre_str_wildcard_compare(*text, pattern))
			arr[i++] = ft_strdup(*text);
		text++;
	}
	arr[i] = NULL;
	arr2 = malloc(sizeof(char **) * (i + 1));
	if (! arr2)
		return (arr);
	i = -1;
	while (arr[++i])
		arr2[i] = arr[i];
	arr2[i] = NULL;
	free(arr);
	return (arr2);
}

char	*expand_wildcard_cwd_str(char *wildcard)
{
	char	*result;
	char	**files;

	files = expand_wildcard_arr(wildcard);
	result = ft_anti_split(quote_str_with_spec(files), " ");
	ft_free_text(files);
	return (result);
}

static int	skip_word(char *word)
{
	if (word[0] == '-' || find_first_char(word, '*') == -1)
		return (1);
	return (0);
}

char	*expand_wildcard_in_str(char *str)
{
	char	**words;
	char	*tmp_word;
	int		i;

	if (str == NULL)
		return (NULL);
	if (*str == 0)
		return (ft_strdup(""));
	words = ft_split(str, ' ');
	if (! words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		if (skip_word(words[i++]))
			continue ;
		tmp_word = words[i - 1];
		words[i - 1] = expand_wildcard_cwd_str(tmp_word);
		free(tmp_word);
	}
	tmp_word = ft_anti_split(words, " ");
	ft_free_text(words);
	if (! tmp_word)
		return (NULL);
	return (tmp_word);
}
