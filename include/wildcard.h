/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/06/02 17:03:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H

# define TMP_FILE_NAME ".tmp_file"
# define LLI_MIN "9223372036854775808"
# define LLI_MAX "9223372036854775807"
# define MAX_PATH_LEN 4096

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft.h"
# include "eclown_utils.h"

typedef struct s_str
{
	char			*value;
	struct s_str	*next;
}	t_str;

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_str	*next;
}	t_dict;

typedef struct s_2int2
{
	int	s[2];
	int	p[2];
}	t_2int2;

char	**apply_wildcard(char *pattern, char **text);
int		total_compare(char *str, char *ptrn);
int		get_lines_count(char **text);
int		find_first_char(char *str, char c);
char	*ec_str_copy(char *str, int cut_start, int cut_end);
char	**ls_cwd(char *path);
char	*ft_anti_split(char **strings, char *separator);
char	*expand_wildcard_cwd(char *wildcard);
char	**ft_list_to_strings(t_list *list);
void	ft_list_remove_all(t_list **list, void (*del)(void *));
char	*expand_wildcard_in_str(char *str);
int		is_char_in_quotes(char *str, char *c);
char	*remove_quotes(char *str);
char	*open_quotes(char *str);
int		symb_count_before_char(char c, char *str, char *before);
int		symb_count_after_char(char c, char *after);
int		pre_str_wildcard_compare(char *str, char *ptrn);

void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
void	ft_list_remove_all(t_list **list, void (*del)(void *));
int		ft_list_remove_current(t_list **list, t_list *current, \
	void (*del)(void *));
void	ft_list_remove(t_list *list, void (*del)(void *));
size_t	ft_list_get_count(t_list *list);
t_list	*ft_list_get_last(t_list *list);
t_list	*ft_list_get_prev(t_list *list, t_list *current);
void	ft_list_iter(t_list *list, void (*fun)(void *));
t_list	*ft_list_map(t_list *list, void *(*fun)(void *), void (*del)(void *));
t_list	*ft_list_new(void *content);
char	**ft_list_to_strings(t_list *list);

t_list	*ft_strings_to_list(char **strings);

#endif  /* WILDCARD_H */
