/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:10:38 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/16 13:49:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

struct s_list
{
	void			*data;
	struct s_list	*next;
};

typedef struct s_list	t_list;

# define LIST_FAILED			NULL
# define LIST_EMPTY				NULL
# define LIST_END				NULL
# define LIST_NOT_FOUND			NULL
# define LIST_DO_NOT_FREE_DATA	NULL

//		Adds an element to the top of the list.
void	ft_list_append_front(t_list **head, t_list *element);

//		Adds an element to the end of the list.
void	ft_list_append(t_list **head, t_list *element);

//		Returns the number of elements in the list.
size_t	ft_list_count(t_list *head);

//		Creates a new list element.
t_list	*ft_list_init(void *data);

//		Creates new data.
void	ft_list_iter(t_list *head, void (*function)(void *));

//		Returns the last element from the list.
t_list	*ft_list_last(t_list *head);

//		Creates a new list with new data.
t_list	*ft_list_map(\
		t_list *head, void *(*function)(void *), void (*remove)(void *));

//		Returns the previous element from the list.
t_list	*ft_list_prev(t_list *list, t_list *element);

//		Removes all elements from the list.
void	ft_list_remove_all(t_list **list, void (*remove)(void *));

//		Removes the first element.
void	ft_list_remove_first(t_list **list, void (*remove)(void *));

//		Remove an element from the list.
int		ft_list_remove_from_list(\
		t_list **head, t_list *element, void (*remove)(void *));

// 		Removes the last element.
void	ft_list_remove_last(t_list **head, void (*remove)(void *));

//		Removes a list element.
void	ft_list_remove(t_list *element, void (*remove)(void *));

#endif // FT_LIST_H
