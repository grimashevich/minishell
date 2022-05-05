/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:28:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/04 19:50:09 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <stddef.h>

char	**ft_string_to_strings(char *string, char *splitter);
void	ft_strings_append(char ***strings, char *string);
size_t	ft_strings_count(char **strings);
char	**ft_strings_dup(char **strings);
int		ft_strings_get_index(char **strings, char *part);
char	*ft_strings_get_string(char **strings, char *part);
void	ft_strings_insert(char ***strings, char *string, int index);
char	**ft_strings_map(char **strings, char *(*fun)(char *));
int		ft_strings_print(char **strings);
void	ft_strings_remove_all(char ***strings);
void	ft_strings_remove_by_part(char ***strings, char *part);
void	ft_strings_remove_first(char ***strings);
void	ft_strings_remove_last(char ***strings);
void	ft_strings_remove(char ***strings, int index);
int		ft_strings_replace_by_part(char **strings, char *string, char *part);
int		ft_strings_replace(char **strings, char *string, int index);
char	*ft_strings_to_string(char **strings, char *splitter);

#endif // FT_STRINGS_H
