# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 22:56:37 by ccamie            #+#    #+#              #
#    Updated: 2022/05/11 22:04:29 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	library/libft.a

CC			=	cc

CPPFLAGS	=	-Wall -Wextra -Werror	\
				-I include

AR			=	ar
ARFLAGS		=	crs

MKDIR		=	mkdir -p
RMDIR		=	rm -rf
RM			=	rm -f

HEADER		=	$(addprefix include/,	\
				ft_ctype.h				\
				ft_list.h				\
				ft_memory.h				\
				ft_string.h				\
				ft_strings.h			\
				libft.h					\
				)

FUNCTIONS	=	$(addprefix ctype/,			\
				ft_digittoint.c				\
				ft_isalnum.c				\
				ft_isalpha.c				\
				ft_isascii.c				\
				ft_isblank.c				\
				ft_iscntrl.c				\
				ft_isdigit.c				\
				ft_isgraph.c				\
				ft_islower.c				\
				ft_isprint.c				\
				ft_ispunct.c				\
				ft_isspace.c				\
				ft_isupper.c				\
				ft_isxdigit.c				\
				ft_toascii.c				\
				ft_toupper.c				\
				ft_tolower.c				\
				)

FUNCTIONS	+=	$(addprefix list/,			\
				ft_list_append_front.c		\
				ft_list_append.c			\
				ft_list_count.c				\
				ft_list_init.c				\
				ft_list_iter.c				\
				ft_list_last.c				\
				ft_list_map.c				\
				ft_list_prev.c				\
				ft_list_print.c				\
				ft_list_remove_all.c		\
				ft_list_remove_first.c		\
				ft_list_remove_from_list.c	\
				ft_list_remove_last.c		\
				ft_list_remove.c			\
				ft_list_to_strings.c		\
				ft_strings_to_list.c		\
				)

FUNCTIONS	+=	$(addprefix memory/,		\
				ft_calloc.c					\
				ft_memccpy.c				\
				ft_memchr.c					\
				ft_memcmp.c					\
				ft_memcpy.c					\
				ft_memmove.c				\
				ft_memset.c					\
				)

FUNCTIONS	+=	$(addprefix string/,		\
				ft_atoi.c					\
				ft_atol.c					\
				ft_itoa.c					\
				ft_putchar_fd.c				\
				ft_putendl_fd.c				\
				ft_putnum_fd.c				\
				ft_putstr_fd.c				\
				ft_split.c					\
				ft_strchr.c					\
				ft_strcmp.c					\
				ft_strcpy.c					\
				ft_strdup.c					\
				ft_strend.c					\
				ft_striteri.c				\
				ft_strjoin.c				\
				ft_strlcat.c				\
				ft_strlcpy.c				\
				ft_strlen.c					\
				ft_strmapi.c				\
				ft_strncmp.c				\
				ft_strnstr.c				\
				ft_strrchr.c				\
				ft_strstr.c					\
				ft_strtrim.c				\
				ft_substr.c					\
				)

FUNCTIONS	+=	$(addprefix strings/,		\
				ft_string_to_strings.c		\
				ft_strings_append.c			\
				ft_strings_count.c			\
				ft_strings_dup.c			\
				ft_strings_get_index.c		\
				ft_strings_get_string.c		\
				ft_strings_insert.c			\
				ft_strings_map.c			\
				ft_strings_print.c			\
				ft_strings_remove_all.c		\
				ft_strings_remove_by_part.c	\
				ft_strings_remove_first.c	\
				ft_strings_remove_last.c	\
				ft_strings_remove.c			\
				ft_strings_replace_by_part.c\
				ft_strings_replace.c		\
				ft_strings_to_string.c		\
				)

SOURCE		=	$(addprefix source/, $(FUNCTIONS))
OBJECT		=	$(addprefix object/, $(FUNCTIONS:.c=.o))
FOLDER		=	$(sort $(dir object/ $(OBJECT) $(NAME)))

.SUFFIXES	:
.SUFFIXES	:	.c .o

.PHONY		:	all clean fclean re

all			:	$(FOLDER) $(NAME)

$(NAME)		:	$(OBJECT)
				$(AR) $(ARFLAGS) $(NAME) $?

$(FOLDER)	:
				$(MKDIR) $@

object/%.o	:	source/%.c $(HEADER)
				$(CC) $(CPPFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJECT)
				$(RMDIR) $(FOLDER)

fclean		:
				$(RM) $(OBJECT)
				$(RM) $(NAME)
				$(RMDIR) $(FOLDER)

re			:	fclean all
