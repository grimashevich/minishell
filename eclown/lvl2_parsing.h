/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/05/13 21:21:28 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LVL2_PARSING_H
# define LVL2_PARSING_H

# include "../libft/libft.h"
# include "../minishell.h"

enum Rdr_type
{
	WRITE,
	APPEND,
	READ,
	HERE_DOC
};

/* 
Keep filenames and fd's from command
default fd:
	0 for '<' redirect
	1 for '>' redirect
Example:
3<file1 echo abc >file2 2>file3 4>file4
 */

typedef struct s_rdr_fls
{
	int					type;
	int					fd;
	char				*path;
	struct s_rdr_fls	*next;
} t_rdr_fls;

typedef struct s_rdr_ptrn
{
	enum Rdr_type	type;	
	int				start;
	int				end;
	int				fd;
} t_rdr_ptrn;

#endif  /* LVL2_PARSING_H */
