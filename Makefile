# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 21:20:20 by EClown            #+#    #+#              #
#    Updated: 2022/05/28 20:32:53 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	minishell

LIBFT		=	libft/library/libft.a

CC			=	cc

CPPFLAGS	=	-I libft/include			\
				-I include
CPPFLAGS	+=	-Wall -Wextra -Werror -g
# CPPFLAGS	+=	-g
# CFLAGS		+=	-fsanitize=address
# CFLAGS		+=	-fsanitize=undefined

LDFLAGS 	=	-lreadline

RM			=	rm -f
MKDIR		=	mkdir -p
RMDIR		=	rm -rf

HEADER		=	libft/include/libft.h			\
				$(addprefix include/,			\
				cd_function.h					\
				eclown_utils.h					\
				executor.h						\
				minishell.h						\
				parser.h						\
				wildcard.h						\
				)

FUNCTIONS	=	$(addprefix builtin/,				\
				echo.c								\
				exit.c								\
				export.c							\
				pwd.c								\
				unset.c								\
				)

FUNCTIONS	+=	$(addprefix eclown/,				\
				$(addprefix utils/,					\
					ft_free_text.c					\
					ft_is_str_equal.c				\
					ft_max_min_int.c				\
					ft_split_new.c					\
					ft_strjoin3.c					\
					)								\
				cd_function.c						\
				lvl2_parsing.c						\
				)

FUNCTIONS	+=	$(addprefix envp/,					\
				envp_append.c						\
				envp_count.c						\
				envp_get_index.c					\
				envp_get_value.c					\
				envp_init.c							\
				envp_insert.c						\
				envp_print.c						\
				envp_remove_all.c					\
				envp_remove_by_index.c				\
				envp_remove_first.c					\
				envp_remove_last.c					\
				envp_remove.c						\
				envp_replace_by_index.c				\
				envp_replace.c						\
				envp_status.c						\
				)


FUNCTIONS	+=	$(addprefix executor/,				\
				assign_vars_value.c					\
				executor.c							\
				)

FUNCTIONS	+=	$(addprefix parser/,				\
				$(addprefix check_syntax/,			\
					check_syntax_all.c				\
					check_quotation_mark_syntax.c	\
					check_syntax_of_operators.c		\
					check_syntax_of_parentheses.c	\
					check_syntax_of_redirect.c		\
					check_syntax.c					\
					)								\
				$(addprefix print/,					\
					print_diagram.c					\
					print_tree.c					\
					)								\
				count_the_number_of_operators.c		\
				get_command.c						\
				get_container.c						\
				give_a_line_before_operator.c		\
				parser.c							\
				remove_insignificant.c				\
				just_print.c						\
				)

FUNCTIONS	+=	$(addprefix utils/,					\
				ls_cwd_antisplit.c					\
				ls_cwd.c							\
				ms_error.c							\
				)

FUNCTIONS	+=	$(addprefix wildcard/,				\
				eclown_func1.c						\
				wildcard_1.c						\
				wildcard_2.c						\
				)

FUNCTIONS	+=	main.c

SOURCE		=	$(addprefix source/, $(FUNCTIONS))
OBJECT		=	$(addprefix object/, $(FUNCTIONS:.c=.o))
FOLDER		=	$(sort $(dir object/ $(OBJECT)))

.SUFFIXES	:
.SUFFIXES	:	.c .o

.PHONY		:	all clean fclean re libft

all			:	libft $(FOLDER) $(NAME)

$(NAME)		:	$(OBJECT) 
				$(CC) $(LDFLAGS) $(CFLAGS) $(OBJECT) $(LIBFT) -o $(NAME)

$(FOLDER)	:
				$(MKDIR) $@

object/%.o	:	source/%.c $(HEADER)
				$(CC) $(CPPFLAGS) -c $< -o $@

libft		:
				make -C libft

clean		:
				$(RM) $(OBJECT)
				$(RMDIR) $(FOLDER)
				make clean -C libft

fclean		:
				$(RM) $(OBJECT)
				$(RM) $(NAME)
				$(RMDIR) $(FOLDER)
				make fclean -C libft

re			:	fclean all



# NAME := minishell
# CC := clang
# OBJ_DIR := obj
# EC_FUNC_FOLDER := eclown_funcs


# LIBFT_DIR := libft
# LIBFT_LIB := $(LIBFT_DIR)/libft.a

# CFLAGS := -Wall -Wextra -Werror -g
# CPPFLAGS := -I$(LIBFT_DIR) -MMD
# S_FLAGS := -fsanitize=address
# LDFLAGS := -L$(LIBFT_DIR) -lreadline
# LDLIBS := -lft

# SRC_C :=	$(wildcard utils/*.c)		ls_cwd_antisplit.c		ls_cwd.c

# SRC_EC :=	eclown_func1.c	wildcard_1.c	wildcard_2.c

# SRC_EC := $(SRC_EC:%.c=$(EC_FUNC_FOLDER)/%.c)

# SRC_M :=	main.c

# SRC_B :=	main.c

# SRC := 		$(SRC_C) $(SRC_M) $(SRC_EC)
# SRC_B :=	$(SRC_B) $(SRC_C)

# OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
# OBJ_B := $(SRC_B:%.c=$(OBJ_DIR)/%.o)

# DEP := $(OBJ:.o=.d)
# DEP_B := $(OBJ_B:.o=.d)

# .PHONY: all clean fclean re bonus

# all:	$(NAME)
# bonus:
# 	@make OBJ="$(OBJ_B)" DEP="$(DEP_B)" all

# $(NAME): $(LIBFT_LIB) $(OBJ)
# 	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) $(S_FLAGS) -o $(NAME)

# $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) 
# 	$(CC) $(CFLAGS) $(CPPFLAGS) $(S_FLAGS) -c $< -o $@

# $(OBJ_DIR):
# 	mkdir -p $@

# $(LIBFT_LIB): libft1

# libft1:
# 	@$(MAKE) -C $(LIBFT_DIR)

# -include $(DEP) $(DEP_B)

# clean:
# 	@rm -f $(OBJ) $(DEP) $(OBJ_B) $(DEP_B)
	

# fclean: clean
# 	@rm -f $(NAME) $(NAME_B)
# 	make fclean -C libft

# re: fclean all

