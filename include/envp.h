/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:03:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/06 20:47:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include <stddef.h>

void	envp_append(char *variable, char *value);
size_t	envp_count(void);
int		envp_get_index(char *variable);
char	*envp_get_value(char *variable);
void	envp_init(char **envp);
void	envp_insert(char *variable, char *value, int index);
void	envp_print(void);
void	envp_remove_all(void);
void	envp_remove_first(void);
void	envp_remove_last(void);
void	envp_remove_by_index(int index);
void	envp_remove(char *variable);
void	envp_replace_by_index(char *variable, char *value, int index);
void	envp_replace(char *variable, char *value);
void	envp_status(void);

#endif // ENVP_H
