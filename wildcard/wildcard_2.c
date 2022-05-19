/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:36:31 by EClown            #+#    #+#             */
/*   Updated: 2022/05/19 19:52:14 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int		compare_start(char *str, char *ptrn);
int		compare_end(char *str, char *ptrn);
int		compare_closed_str(char *str, char *ptrn);
char	*str_join_3(char *str1, char *str2, char *str3);
char	*encode_spec_chars_quotes_str(char *str);

int	str_wildcard_compare(char *str, char *ptrn)
{
	int		star_cut;
	int		end_cut;
	char	*closed_str;
	char	*closed_ptrn;
	int		result;

	if (find_first_char(ptrn, '*') == -1)
	{
		if (ft_strncmp(str, ptrn, ft_max_int(ft_strlen(str), ft_strlen(ptrn))) == 0)
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
	if (! closed_ptrn)
	{
		free(closed_str);
		return(0);
	}
	result = compare_closed_str(closed_str, closed_ptrn);
	free(closed_str);
	free(closed_ptrn);
	return (result);
}

static void replace_sym_to_minus_q(char *str, char c)
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

static void replace_sym_to_minus(char *str, char c)
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

int pre_str_wildcard_compare(char *str, char *ptrn)
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

char	**apply_wildcard(char *pattern, char** text)
{
	int		count;
	char	**arr;
	char	**arr2;
	int		i;

	count = get_lines_count(text);
	arr = malloc(sizeof(char **) * (count + 1));
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

static void hide_hidden_fles(char **files, char * wildcard)
{
	int i = 0;

	//if (ft_strncmp(wildcard, ".*", 3) == 0)
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
char *put_str_in_quotes(char *str, char quote, int need_free)
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

int is_spec_in_string(char *str)
{
	int	spec_in_str;

	if (! str)
		return (0);
	while (*str)
	{
		spec_in_str = ft_isspace(*str) || ft_strchr("<>*\"", *str);
		if (spec_in_str)
			return (1);
		str++;
	}
	return (0);
}

char *escape_single_quotes(char *str, int need_free)
{
	char	**splits;
	char	*result;
	//int		i;

	if (str == NULL)
		return (NULL);
	splits = ft_split_new(str, '\'');
/* 	i = 0;
	while (splits[i])
	{
		splits[i] = put_str_in_quotes(splits[i], '\'', 1);\
		i++;
	} */
	result = ft_anti_split(splits, "'\\''");
	ft_free_text(splits);
	result = put_str_in_quotes(result, '\'', 1);
	if (need_free)
		free(str);
	return (result);
}

char **quote_str_with_spec(char **text)
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

/* char	*expand_wildcard_cwd(char *wildcard)
{
	char	*cwd;
	char	**files;
	char	**result_files;
	char	*result;

	if (wildcard == NULL)
		return (NULL);
	if (*wildcard == 0)
		return (ft_strdup("")); //TODO Уточнить что возвращаем
	cwd = malloc(MAX_PATH_LEN);
	if (! cwd)
		return (NULL);
	getcwd(cwd, MAX_PATH_LEN); //TODO Заменить на нашу переменную cwd когда она заработает
	files = ls_cwd(cwd);		//TODO Возвращает массив с освобожденной памятью
	free(cwd);
	if (! files)
		return (NULL);
	hide_hidden_fles(files, wildcard);	
	result_files = apply_wildcard(wildcard, files);
	ft_free_text(files);
	if (!result_files || !result_files[0])
		return (ft_strjoin3("'", wildcard, "'"));
	result = ft_anti_split(quote_str_with_spec(result_files), " ");
	ft_free_text(result_files);
	return (result);
} */

int text_len(char **text)
{
	int	result;

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
	new_text[i] =  NULL;
	free(text);
	return(new_text);
}

char	**add_text_to_text(char **dest, char **added, int need_free)
{
	int		total_len;
	char	**new_text;
	int		i;

	if (dest == NULL && added == NULL)
		return (NULL);
	total_len = text_len(dest) + text_len(added);
	new_text = malloc(sizeof(char *) * (total_len + 1));
	if (! new_text)
		return (NULL);
	i = 0;
	while (*dest)
		new_text[i++] = *(dest++);
	while (*added)
		new_text[i++] = *(added++);
	new_text[i] = NULL;
	if (need_free)
	{
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
		return (NULL);
	cwd = malloc(MAX_PATH_LEN);
	if (! cwd)
		return (NULL);
	getcwd(cwd, MAX_PATH_LEN); //TODO Заменить на нашу переменную cwd когда она заработает
	files = ls_cwd(cwd);		//TODO Возвращает массив с освобожденной памятью
	free(cwd);
	if (! files)
		return (NULL);
	hide_hidden_fles(files, wildcard);	
	result_files = apply_wildcard(wildcard, files);
	if (!result_files || !result_files[0])
		return (add_str_to_text(ft_strjoin3("'", wildcard, "'"), NULL));
	return (result_files);
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

static int skip_word(char *word)
{
	if (word[0] == '-' || find_first_char(word, '*') == -1)
		return (1);
	return(0);
}

/* Get command string, return command string with expanded wildcard '*' */

/*
case: "tes"*"file” → testfile

*/

char	*expand_wildcard_in_str(char *str)
{
	char	**words;
	char	*tmp_word;
	int		i;

	if (str == NULL)
		return (NULL);
	if (*str == 0)
		return(ft_strdup(""));
	words = ft_split(str, ' ');
	if (! words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		if (skip_word(words[i++]))
			continue;
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
