/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:10:38 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/12 15:10:41 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

void	ft_list_add_back(t_list **list, t_list *new);
void	ft_list_add_front(t_list **list, t_list *new);
size_t	ft_list_count(t_list *list);
void	ft_list_iter(t_list *list, void (*fun)(void *));
t_list	*ft_list_last(t_list *list);
t_list	*ft_list_map(t_list *list, void *(*fun)(void *), void (*del)(void *));
t_list	*ft_list_new(void *data);
t_list	*ft_list_prev(t_list *list, t_list *current);
int		ft_list_print(t_list *list, int fd);
void	ft_list_remove_all(t_list **list, void (*del)(void *));
int		ft_list_remove_current(t_list **list, t_list *current, void (*del)(void *));
void	ft_list_remove(t_list *list, void (*del)(void *));
char	**ft_list_to_strings(t_list *list);
t_list	*ft_strings_to_list(char **strings);

#endif // FT_LIST_H
