# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 00:00:23 by ccamie            #+#    #+#              #
#    Updated: 2022/05/16 16:53:40 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	library/libunit.a

CC			=	cc

CPPFLAGS	=	-Wall -Wextra -Werror	\
				-I include

AR			=	ar
ARFLAGS		=	crs

MKDIR		=	mkdir -p
RMDIR		=	rm -rf
RM			=	rm -f

HEADER		=	$(addprefix include/,		\
				ft_list.h					\
				unittest.h					\
				)

FUNCTIONS	=	$(addprefix list/,			\
				ft_list_append_front.c		\
				ft_list_append.c			\
				ft_list_count.c				\
				ft_list_init.c				\
				ft_list_iter.c				\
				ft_list_last.c				\
				ft_list_map.c				\
				ft_list_prev.c				\
				ft_list_remove_all.c		\
				ft_list_remove_first.c		\
				ft_list_remove_from_list.c	\
				ft_list_remove_last.c		\
				ft_list_remove.c			\
				)

FUNCTIONS	+=	$(addprefix unittest/,	\
				file.c					\
				signal.c				\
				status.c				\
				test_leak.c				\
				test.c					\
				timeout.c				\
				)

FUNCTIONS	+=	$(addprefix utils/,	\
				get_int.c			\
				get_output.c		\
				get_string.c		\
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
