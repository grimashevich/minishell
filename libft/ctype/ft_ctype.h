/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:11 by ccamie            #+#    #+#             */
/*   Updated: 2022/04/30 14:46:15 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

// converts the operand to integer
int	ft_digittoint(int character);

// checks whether the operand is alphanumeric
int	ft_isalnum(int character);

// checks whether the operand is alphabetic
int	ft_isalpha(int character);

// checks whether the operand is ascii
int	ft_isascii(int character);

// checks whether the operand is a blank space character
int	ft_isblank(int character);

// checks whether the operand is a control character
int	ft_iscntrl(int character);

// checks whether the operand is a digit
int	ft_isdigit(int character);

// checks whether the operand is a graphical character
int	ft_isgraph(int character);

// checks whether the operand is lowercase
int	ft_islower(int character);

// checks whether the operand is a printable character
int	ft_isprint(int character);

// checks whether the operand is punctuation
int	ft_ispunct(int character);

// checks whether the operand is space
int	ft_isspace(int character);

// checks whether the operand is an uppercase
int	ft_isupper(int character);

// checks whether the operand is hexadecimal
int	ft_isxdigit(int character);

// converts the operand to ascii
int	ft_toascii(int character);

// converts the operand to lowercase
int	ft_tolower(int character);

// converts the operand to uppercase
int	ft_toupper(int character);

#endif // FT_CTYPE_H
