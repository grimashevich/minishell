/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:38 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:18:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

int		ft_atoi(char *string);
long	ft_atol(char *string);
char	*ft_itoa(int num);
int		ft_putchar_fd(char character, int fd);
int		ft_putendl_fd(char *string, int fd);
int		ft_putnum_fd(int num, int fd);
int		ft_putstr_fd(char *string, int fd);
char	**ft_split(char *string, int splitter);
char	*ft_strchr(char *string, char character);
int		ft_strcmp(char *one, char *two);
void	ft_strcpy(char *from, char *in);
char	*ft_strdup(char *string);
int		ft_strend(char *string, char *ending);
void	ft_striteri(char *string, void (*func)(unsigned int, char *));
char	*ft_strjoin(char *one, char *two);
size_t	ft_strlcat(char *from, char *in, size_t lenght);
size_t	ft_strlcpy(char *from, char *in, size_t length);
size_t	ft_strlen(char *string);
char	*ft_strmapi(char *string, char (*func)(unsigned int, char));
int		ft_strncmp(char *one, char *two, size_t length);
char	*ft_strnstr(char *haystack, char *needle, size_t lenght);
char	*ft_strrchr(char *string, int character);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_strtrim(char *string, char *set);
char	*ft_substr(char *string, size_t start, size_t length);

#endif // FT_STRING_H
