# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 22:56:37 by ccamie            #+#    #+#              #
#    Updated: 2022/05/05 21:00:10 by EClown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

HEADER		=	libft.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		+=	-fsanitize=address
# CFLAGS		+=	-fsanitize=undefined
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

SOURCE		=	ctype/ft_digittoint.c	\
				ctype/ft_isalnum.c		\
				ctype/ft_isalpha.c		\
				ctype/ft_isascii.c		\
				ctype/ft_isblank.c		\
				ctype/ft_iscntrl.c		\
				ctype/ft_isdigit.c		\
				ctype/ft_isgraph.c		\
				ctype/ft_islower.c		\
				ctype/ft_isprint.c		\
				ctype/ft_ispunct.c		\
				ctype/ft_isspace.c		\
				ctype/ft_isupper.c		\
				ctype/ft_isxdigit.c		\
				ctype/ft_toascii.c		\
				ctype/ft_toupper.c		\
				ctype/ft_tolower.c		\
				list/ft_list_add_back.c			\
				list/ft_list_add_front.c		\
				list/ft_list_count.c			\
				list/ft_list_iter.c				\
				list/ft_list_last.c				\
				list/ft_list_map.c				\
				list/ft_list_new.c				\
				list/ft_list_prev.c				\
				list/ft_list_print.c			\
				list/ft_list_remove_all.c		\
				list/ft_list_remove_current.c	\
				list/ft_list_remove.c			\
				list/ft_list_to_strings.c		\
				list/ft_strings_to_list.c		\
				memory/ft_calloc.c		\
				memory/ft_memccpy.c		\
				memory/ft_memchr.c		\
				memory/ft_memcmp.c		\
				memory/ft_memcpy.c		\
				memory/ft_memmove.c		\
				memory/ft_memset.c		\
				string/ft_atoi.c			\
				string/ft_atol.c			\
				string/ft_itoa.c			\
				string/ft_putchar_fd.c		\
				string/ft_putendl_fd.c		\
				string/ft_putnum_fd.c		\
				string/ft_putstr_fd.c		\
				string/ft_split.c			\
				string/ft_strchr.c			\
				string/ft_strcmp.c			\
				string/ft_strcpy.c			\
				string/ft_strdup.c			\
				string/ft_strend.c			\
				string/ft_striteri.c		\
				string/ft_strjoin.c			\
				string/ft_strlcat.c			\
				string/ft_strlcpy.c			\
				string/ft_strlen.c			\
				string/ft_strmapi.c			\
				string/ft_strncmp.c			\
				string/ft_strnstr.c			\
				string/ft_strrchr.c			\
				string/ft_strstr.c			\
				string/ft_strtrim.c			\
				string/ft_substr.c			\
				strings/ft_string_to_strings.c			\
				strings/ft_strings_append.c				\
				strings/ft_strings_count.c				\
				strings/ft_strings_dup.c				\
				strings/ft_strings_get_index.c			\
				strings/ft_strings_get_string.c			\
				strings/ft_strings_insert.c				\
				strings/ft_strings_map.c				\
				strings/ft_strings_print.c				\
				strings/ft_strings_remove_all.c			\
				strings/ft_strings_remove_by_part.c		\
				strings/ft_strings_remove_first.c		\
				strings/ft_strings_remove_last.c		\
				strings/ft_strings_remove.c				\
				strings/ft_strings_replace_by_part.c	\
				strings/ft_strings_replace.c			\
				strings/ft_strings_to_string.c			\

OBJECT		=	$(SOURCE:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJECT) 
				$(AR) $(ARFLAGS) $(NAME) $?

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJECT)

fclean		:
				$(RM) $(OBJECT)
				$(RM) $(NAME)

re			:	fclean all
