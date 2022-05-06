/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclown_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/05/06 13:23:16 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECLOWN_UTILS_H
# define ECLOWN_UTILS_H

# include "../../minishell.h"

void	ft_free_text(char **text);
int		ft_max_int(int n1, int n2);
int		ft_min_int(int n1, int n2);
char	**ft_split_new(char *str, char sep);
char	*ft_strjoin3(char *str1, char *str2, char *str3);

#endif  /* ECLOWN_UTILS_H */
