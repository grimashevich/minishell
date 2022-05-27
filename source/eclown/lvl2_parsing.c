/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:04:22 by EClown            #+#    #+#             */
/*   Updated: 2022/05/27 16:10:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_char_in_quotes(char *str, char *c);
void	encode_quotes_str(char *str, char *char2encode);
char	**add_text_to_text(char **dest, char **added, int need_free);
char	**expand_wildcard_arr(char *wildcard);
void	decode_text(char **text);
void	open_quotes_text(char **text);
char	**add_str_to_text(char *str, char **text);
void	expand_vars(char **cmd, t_vars *vars, int need_unquote);

char *empty_str_instead_null(char *str)
{
	if (! str)
		return (ft_strdup(""));
	return (str);
}

t_vars	*create_var(char *name, char *value)
{
	t_vars	*result;

	result = ft_calloc(1, sizeof(t_vars));
	if (! result)
		return (NULL);
	if (name)
		result->name = ft_strdup(name);
	if (value)
		result->value = ft_strdup(value);
	return (result);
}

t_vars	*add_var_first(t_vars *start, t_vars *new_var)
{
	if (! new_var)
		return (start);
	if (! start)
		return (new_var);
	new_var->next = start;
	return (new_var);
}

void	set_var_global(t_vars *start, char *name)
{
	while (start)
	{
		if (ft_strcmp(start->name, name) == 0)
		{
			start->is_global = 1;
			return ;
		}
		start = start->next;
	}
}

char	*get_var_value(t_vars *start, char *name)
{
	while (start)
	{
		if (ft_strcmp(start->name, name) == 0)
			return (start->value);
		start = start->next;
	}
	return (NULL);
}

void free_var(t_vars *item)
{
	if (! item)
		return ;
	if (item->name)
		free(item->name);
	if (item->value)
		free(item->value);
	free(item);
}

t_vars	*delete_var(t_vars *start, char *name)
{
	t_vars	*prev;
	t_vars	*tmp;
	t_vars	*cur;

	if (start == NULL)
		return (NULL);
	if (ft_strcmp(name, start->name) == 0)
	{
		tmp = start->next;
		free_var(start);
		return (tmp);
	}
	cur = start;
	while (cur)
	{
		if (ft_strcmp(cur->name, name) == 0)
		{
			prev->next = cur->next;
			free_var(cur);
			return (start);
		}
		prev = cur;
		cur = cur->next;
	}
	return (start);
}

void	delete_all_vars(t_vars *start)
{
	while (start)
	{
		start = delete_var(start, start->name);
	}
}

t_vars	*update_vars(t_vars *start, char *name, char *new_value)
{
	t_vars	*tmp;

	tmp = delete_var(start, name);
	return (add_var_first(tmp, create_var(name, new_value)));
}

char **split_with_quotes(char *str, char sep, int need_unquote)
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
int is_var_assign(char *str, t_vars **out_var)
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
	if (! out_var)
		return (0);
	(*out_var)->name = ft_substr(str, 0, i);
	(*out_var)->value = ft_substr(&str[i + 1], 0, ft_strlen(&str[i + 1]));
	return (1);
}


// IT WORKS AFTER extraxt all redirects
// So, in start of the lone we can see only var assignation or command
// All text after command will be parametrs of this command
t_vars *extract_var_assign(char *str, char **out_cmd_wout_assign, int free_old_cmd, t_vars *ms_vars)
{
	char	**splits;
	t_vars	*result;
	t_vars	*tmp;
	int		i;

	splits = split_with_quotes(str, ' ', 0);
	if (! splits)
		return (NULL);
	i = 0;
	if (free_old_cmd)
		free(str);
	result = NULL;
	*out_cmd_wout_assign = NULL;
	tmp = NULL;
	while (splits[i])
	{
		if (is_var_assign(splits[i], &tmp))
		{
			expand_vars(&(tmp->value), ms_vars, 0);
			result = add_var_first(result, tmp);
		}
		else
			break;
		i++;
	}
	*out_cmd_wout_assign = empty_str_instead_null(ft_anti_split(&(splits[i]), " "));
	ft_free_text(splits);
	return (result);
	//1. Разделяем на цельные слова с учетом скобок
	//2. Сплитим
	//3. Ппробегаемся циклом по всем словам и выясняем переменная ли это.
	//4. Если переменная, добавляем её в структуру временных присвоейний
	//		Если нет, джойним к строке через пробел, собирая новую строку без присвоений
	
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

char *open_quotes_with_free(char *str)
{
	char	*new_str;

	if (! str)
		return (NULL);
	new_str = open_quotes(str);
	free(str);
	return(new_str);
}

char *strdup_null_safe(char *str)
{
	if (! str)
		return ft_strdup("");
	return ft_strdup(str);
}

void	expand_vars(char **cmd, t_vars *vars, int need_unquote)
{
	char	*tmp;
	char	*tmp2;
	char	*var_name;
	int		name_len;
	char	*var_value;

	tmp = *cmd;
	tmp = ft_strchr(tmp, '$');
	while (tmp)
	{
		name_len = get_var_name_len(tmp, &var_name);
		if (name_len > 0 && is_char_in_quotes(*cmd, tmp)!= '\'')
		{
			if (envp_get_value(var_name))
				var_value = strdup_null_safe(envp_get_value(var_name));
			else
				var_value = strdup_null_safe(get_var_value(vars, var_name));
			if (need_unquote)
				var_value = open_quotes_with_free(var_value);
			tmp2 = *cmd;
			*cmd =  replace_str_in_str(*cmd, tmp, name_len, var_value);
			free(tmp2);
			tmp = *cmd;
			tmp = ft_strchr(&tmp[tmp - *cmd + ft_strlen(var_value)], '$');
			free(var_name);
			free(var_value);
			continue;
		}
		if (var_name)
			free(var_name);
		tmp++;
		tmp = ft_strchr(tmp, '$');
	}
}


/* 
TODO
1. Парсинг присвоения переменных
2. Парсирнг значения переменных в строке


УТВЕРЖДЕНИЯ:
1. Присовение переменных может быть только левее команды, иначе они будут аргументами команды
2. Присовением считается, когда есть символ = и слева находятся alphanumeric
3. Имя переменной может начинаться только с буквы, иначе игнорируется
4. Сначала происходит раскрытие переменных, потом присовение

 */



/* 
#################################################################################################################
#												OLD ZONE														#
#################################################################################################################
 */


int str_is_numeric(char *str)
{
	if (str == NULL || *str == 0)
		return (0);
	while (*str)
	{
		if (! ft_isdigit(*(str++)))
			return (0);
	}
	return (1);
}

t_rdr_fls	*create_rdr_fls(char *path, int fd)
{
	t_rdr_fls	*result;

	if (path == NULL && path[0] == 0)
		return (NULL);
	result = malloc(sizeof(t_rdr_fls));
	if (! result)
		return (NULL);
	result->path = path;
	result->out_files =  NULL;
	if (! result->path)
	{
		free(result);
		return (NULL);
	}
	result->fd = fd;
	result->next = NULL;
	return (result);
}

t_rdr_fls *add_last_rdr_file(t_rdr_fls *start, t_rdr_fls *value)
{
	t_rdr_fls	*tmp;

	if (start == NULL && value == NULL)
		return (NULL);
	if (start == NULL)
		return (value);
	if (value == NULL)
		return (start);
	tmp = start;
	while (start->next)
		start = start->next;
	start->next = value;
	return (tmp);
}

void free_rdr(t_rdr_fls *item)
{
	if (item->path)
		free(item->path);
	if (item->out_files)
		ft_free_text(item->out_files);
	free(item);
}

void free_rdr_list(t_rdr_fls *item)
{
	t_rdr_fls *tmp;

	while (item)
	{
		tmp = item->next;
		free_rdr(item);
		item = tmp;
	}
}

/*
return new string with deleted chars from start index to end index (included)
*/
char* del_from_str(char *str, int start, int end)
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

int is_char_in_str(char c, char *str)
{
	while (*str)
	{
		if (*(str++) == c)
			return (1);
	}
	return (0);
}

/*
Replace char witch contains in char2encode to its negative variant if it in quotes
*/
void encode_quotes_str(char *str, char *char2encode)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_char_in_str(str[i], char2encode) && is_char_in_quotes(str, &str[i]))
			str[i] *= -1;
		i++;
	}
}

void encode_spcs_quotes_str(char *str)
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
		searched_chars = ft_isspace(str[i]) || str[i] == '*';
		searched_chars = searched_chars && is_char_in_quotes(str, &str[i]);
		if (searched_chars)
			str[i] *= -1;
		i++;
	}
	return str;
}


void decode_quotes_str(char *str)
{
	while (*str)
	{
		if (*str < 0)
			*str *= -1;
		str++;
	}
}

/*

Return malloced copy of left word from  char c
	if this word is numeric and if no space
	between char c and word
*/
char *find_num_left_from_char(char *str, char *c)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	if (str == NULL || c == NULL)
		return (NULL);
	i = -1;
	len = 0;
	while (str <= &c[i] && ! ft_isspace(c[i]))
	{
		if (! ft_isdigit(c[i]))
			return (NULL);
		i--;
		len++;
	}
	if (len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (len + 1));
	i++;
	j = 0;
	while (i < 0)
		result[j++] = c[i++];
	result[j] = 0;
	return (result);
}

/* 
Trying to find next word after needle in some string
c - is pointer to first character of needle
RETURN count of chars from end of the needle to end of the first word
	copy (malloced) finded word to pointer *_to_write
 */

int find_word_right_from_needle(char *c, const char *needle, char **to_write)
{
	int	result;
	int	word_len;
	int	i;
	int	_;

	*to_write = NULL;
	if (c == NULL || needle == NULL)
		return (-1);
	i = 0;
	result = 0;
	word_len = 0;
	while (needle[i] && needle[i] == c[i])
		i++;
	while (c[i] && ft_isspace(c[i]))
		_ = word_len >= 0 && i++ == result++;
	while ((c[i] && ! ft_isspace(c[i])) || is_char_in_quotes(&c[i - result], &c[i]))
		_ = 0 <= word_len++ && i++ == result++;
	if (word_len == 0)
		return (-1);
	*to_write = ft_substr(c, i - word_len, word_len);
	return (result);
}

char *get_rdr_type(int type)
{
	if (type == WRITE)
		return (">");
	if (type == APPEND)
		return (">>");
	if (type == READ)
		return ("<");
	if (type == HERE_DOC)
		return ("<<");
	return ("");
}

int get_default_fd_by_rdr_type(int type)
{
	if (type < 2)
		return (1);
	return (0);
}

void delete_rdr_from_str(char **str, int start, int end)
{
	char	*tmp;

	tmp = del_from_str(*str, start, end);
	if (! tmp)
		return ;
	free(*str);
	*str = tmp;
}

int fd_str_len(char *fd_str)
{
	//int	i;
	if (fd_str != NULL)
		return (ft_strlen(fd_str));
	return (0);
/*
TODO DELETE?
	i = 0;
	while (fd)
	{
		fd = fd / 10;
		i++;
	}
	return (i);
*/
}

/* 
cmd > 2 param1
TODO FIX WORKING WITH QUOTES
 */
t_rdr_fls *eject_redirect(char **str, char *c, int rdr_type)
{
	t_rdr_fls	*result;
	char		*fd_str;
	char		*fname;
	int			fd_int;
	int			r_word_len;

	fd_int = get_default_fd_by_rdr_type(rdr_type);
	fd_str = find_num_left_from_char(*str, c);
	if (fd_str)
		fd_int = ft_atoi(fd_str);
	r_word_len = find_word_right_from_needle(c, get_rdr_type(rdr_type), &fname);
	if (r_word_len == -1)
		return (NULL);
	result = create_rdr_fls(fname, fd_int);
	if (! result)
		return (NULL);
	result->type = rdr_type;
	int start_rdr = c - *str;
	(void) start_rdr;
	delete_rdr_from_str(str, 
		c - *str - fd_str_len(fd_str),
		c - *str + ft_strlen((char *) get_rdr_type(rdr_type)) - 1 + r_word_len);
	if (fd_str)
		free(fd_str);
	return (result);
}

/* 
Search next redirect in str, return type of redirect.
if not found, -1 will be returned
put into *out_start_rdr pointer to first char of found value
 */
int find_next_redirect(char *str, char **out_start_rdr)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		*out_start_rdr = &str[i];
		if (str[i] == '>')
		{
			if (is_char_in_quotes(str, &str[i]))
				continue;
			if (str[i + 1] == '>')
				return (1);
			return (0);
		}
		if (str[i] == '<')
		{
			if (is_char_in_quotes(str, &str[i]))
				continue ;
			if (str[i + 1] == '<')
				return (3);
			return (2);
		}
	}
	return (-1);
}

t_rdr_fls *extract_all_rdrs(char **str)
{
	t_rdr_fls	*result;
	t_rdr_fls	*cur_rdr;
	char		*cur_rdr_start;
	int			cur_rdr_type;

	result = NULL;
	cur_rdr = NULL;
	cur_rdr_start =  NULL;
	while (1)
	{
		cur_rdr_type = find_next_redirect(*str, &cur_rdr_start);
		if (cur_rdr_type == -1)
			return (result);
		cur_rdr = eject_redirect(str, cur_rdr_start, cur_rdr_type);
		result = add_last_rdr_file(result, cur_rdr);
	}
}

void decode_text(char **text)
{
	while (*text)
		decode_quotes_str(*(text++));	
}

void open_quotes_text(char **text)
{
	char	*tmp;

	while (*text)
	{
		tmp = open_quotes(*text);
		if (! tmp)
			ms_error("open_quotes_text", "malloc error", 1);
		free(*text);
		*text = tmp;
		text++;
	}
}

void	extract_wldcrd_rdrs(t_rdr_fls *rdr_start)
{
	char		**splits;
	int			i;
	while (rdr_start)
	{
		encode_spcs_quotes_str(rdr_start->path);
		splits = ft_split(rdr_start->path, ' ');
		if (! splits)
			return ;
		decode_text(splits);
		i = 0;
		while (splits[i])
		{
			rdr_start->out_files = add_text_to_text(
				rdr_start->out_files,
				expand_wildcard_arr(open_quotes(splits[i++])),
				1);
		}
		ft_free_text(splits);
		//open_quotes_text(rdr_start->out_files);
		decode_quotes_str(rdr_start->path);
		rdr_start = rdr_start->next;
	}
}

void expand_vars_in_rdrs(t_rdr_fls *rdrs, t_vars *ms_vars)
{
	while (rdrs)
	{
		expand_vars(&(rdrs->path), ms_vars, 1);
		rdrs = rdrs->next;
	}
}


/*
INPUT:
malloced t_cmd *cmd_struct
*/
void lvl2_parsing(char *cmd_str, t_cmd *cmd_struct, t_vars *ms_vars)
{
	char	*cmd;
	char	**args;
	char	**tmp;
	int		i;
	char	*str_tmp;

	cmd = ft_strdup(cmd_str);
	if (! cmd)
		return ;
	cmd_struct->redirects = extract_all_rdrs(&cmd);
	expand_vars_in_rdrs(cmd_struct->redirects, ms_vars);
	extract_wldcrd_rdrs(cmd_struct->redirects);
	cmd_struct->vars = extract_var_assign(cmd, &cmd, 1, ms_vars);
	expand_vars(&cmd, ms_vars, 1);
	encode_quotes_str(cmd, " ");
	tmp = ft_split(cmd, ' ');
	if (tmp == NULL)
	{
		free_rdr_list(cmd_struct->redirects);
		return ;
	}
	free(cmd);
	args = NULL;
	decode_text(tmp);
	i = 0;
	while (tmp[i])
	{
		str_tmp = open_quotes(tmp[i++]);
		args = add_text_to_text(args, expand_wildcard_arr(str_tmp),1);
		//free(str_tmp);
	}
	ft_free_text(tmp);
	//open_quotes_text(args);
	if (args == NULL)
		args = add_str_to_text(ft_strdup(""), args);
	cmd_struct->command = args;
}



void free_t_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->command)
		ft_free_text(cmd->command);
	if (cmd->redirects)
		free_rdr_list(cmd->redirects);
	if (cmd->vars)
		delete_all_vars(cmd->vars);
	free(cmd);
}

/* 

1. Извлекаем редиректы (переменные и файлы не могут содержать непосредственно редиректы)
	1.1. В именах файлов редиректов расркрываем переменные
	1.2. В именах файлов редиректов расркрываем * (применяем как к строке, где пробелы - разделители аргументов)
	1.3. В именах файлов редиректов расркрываем кавычки
2. Обрабатываем переменные
	2.1. Извлекаем присвоение переменных
	2.2. Раскрываем переменные
3. Минусим все пробелы, находящиеся внутри кавычек
5. Сплитим команду на бинарник и агргумены
3. Раскрываем *
6. Возвращаем пробелы обратно
7. Раскрываем кавычки

files = file0 file1 file2 file08
var1="*file0*"

0. < infile.txt echo "THE FILES:" *.txt $cFiles > outfile.txt 
1.  echo "1 2 3" *.txt $cFiles
3.	echo "1 2 3" *.txt *.c *.h			($cFiles => *.c *.h)
2.	echo "1_2_3" *.txt *.c *.h
 

КАВЫЧКИ:
Пользователь может ввести кавычки со строки - НАДО РАСКРЫТЬ
Имя файла может содержать кавычки			- НЕ НАДО РАСКРЫВАТЬ

 */