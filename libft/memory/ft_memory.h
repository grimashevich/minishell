/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:58:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/25 17:58:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stddef.h>

void	*ft_calloc(size_t count, size_t size);
void	*ft_memccpy(const void *from, void *to, int character, size_t length);
void	*ft_memchr(void *pointer, int character, size_t length);
int		ft_memcmp(const void *one, const void *two, size_t length);
void	*ft_memcpy(const void *from, void *to, size_t length);
void	*ft_memmove(const void *from, void *to, size_t length);
void	*ft_memset(void *pointer, int character, size_t length);

#endif // FT_MEMORY_H
