/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:38:53 by EClown            #+#    #+#             */
/*   Updated: 2022/06/03 02:44:02 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

char	*escape_single_quotes(char *str, int need_free);
int		is_spec_in_string(char *str);
char	*put_str_in_quotes(char *str, char quote, int need_free);
void	hide_hidden_fles(char **files, char *wildcard);
void	exit_if_null(void *pointer);
char	**encode_file_names(char **text);

char	**quote_str_with_spec(char **text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (ft_strchr(text[i], '\''))
			text[i] = escape_single_quotes(text[i], 1);
		else if (is_spec_in_string(text[i]))
			text[i] = put_str_in_quotes(text[i], '\'', 1);
		i++;
	}
	return (text);
}

int	text_len(char **text)
{
	int	result;

	if (text == NULL)
		return (0);
	result = 0;
	while (*(text++))
		result++;
	return (result);
}

char	**add_str_to_text(char *str, char **text)
{
	int		textlen;
	char	**new_text;
	int		i;

	if (text == NULL)
	{
		new_text = malloc(sizeof(char *) * 2);
		if (! new_text)
			return (NULL);
		new_text[0] = str;
		new_text[1] = NULL;
		return (new_text);
	}
	textlen = text_len(text);
	new_text = malloc(sizeof(char *) * (textlen + 2));
	i = 0;
	while (text[i])
	{
		new_text[i] = text[i];
		i++;
	}
	new_text[i++] = str;
	new_text[i] = NULL;
	free(text);
	return (new_text);
}

char	**add_text_to_text(char **dest, char **added, int need_free)
{
	char	**new_text;
	int		i;
	int		j;

	if (dest == NULL && added == NULL)
		return (NULL);
	new_text = malloc(sizeof(char *) * (text_len(dest) + text_len(added) + 1));
	exit_if_null(new_text);
	i = 0;
	while (dest && dest[i])
	{	
		new_text[i] = dest[i];
		i++;
	}
	j = 0;
	while (added[j])
		new_text[i++] = added[j++];
	new_text[i] = NULL;
	if (need_free)
	{
		if (dest != NULL)
			free(dest);
		free(added);
	}
	return (new_text);
}

/*
return text with files matching with wildcard
*/
char	**expand_wildcard_arr(char *wildcard)
{
	char	*cwd;
	char	**files;
	char	**result_files;

	if (wildcard == NULL)
		return (NULL);
	if (*wildcard == 0)
		return (add_str_to_text(ft_strdup(""), NULL));
	if (! strchr(wildcard, '*'))
		return (add_str_to_text(wildcard, NULL));
	cwd = malloc(MAX_PATH_LEN);
	if (! cwd)
		return (NULL);
	getcwd(cwd, MAX_PATH_LEN);
	files = ls_cwd(cwd);
	free(cwd);
	if (! files)
		return (NULL);
	hide_hidden_fles(files, wildcard);
	result_files = apply_wildcard(wildcard, encode_file_names(files));
	ft_free_text(files);
	if (!result_files || !result_files[0])
		return (add_str_to_text(wildcard, NULL));
	free(wildcard);
	return (result_files);
}
