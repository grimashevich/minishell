# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:40:29 by ccamie            #+#    #+#              #
#    Updated: 2022/05/11 18:36:05 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	library/libtest.a

CC			=	cc
CPPFLAGS	=	-Wall -Wextra -Werror -I include -I ../../include

AR			=	ar
ARFLAGS		=	crs

RM			=	rm -f

HEADER		=	include/libtest.h		\
				../../include/libft.h	\

FUNCTIONS	=	check_signal.c				\
				check_timeout.c				\
				get_output.c				\
				get_value_size_t.c			\
				get_value_int.c				\
				get_value_long.c			\
				get_value_size_t.c			\
				get_value_unsigned_int.c	\
				get_value.c					\
				launch_test_leak.c			\
				launch_test.c				\
				print_test_address.c		\
				print_test.c				\

SOURCE		=	$(addprefix source/, $(FUNCTIONS))

OBJECT		=	$(addprefix object/, $(FUNCTIONS:.c=.o))

.PHONY		:	all clean fclean re

all			:	object $(NAME)

object		:
				mkdir object

$(NAME)		:	$(OBJECT)
				$(AR) $(ARFLAGS) $(NAME) $?

object/%.o	:	source/%.c $(HEADER)
				$(CC) $(CPPFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJECT)

fclean		:
				$(RM) $(OBJECT)
				$(RM) $(NAME)

re			:	fclean all
