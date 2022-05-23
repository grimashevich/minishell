SHELL		=	/bin/sh

NAME		=	minishell

LIBPARSER	=	library/libparser.a

LIBFT		=	libft/library/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
# CFLAGS		+=	-fsanitize=address
# CFLAGS		+=	-fsanitize=undefined
LDFLAGS 	=	-lreadline
RM			=	rm -f

SOURCE		=	main.c															\
				$(wildcard eclown/*.c)											\
				$(wildcard eclown/utils/*.c)									\
				$(wildcard utils/*.c)											\
				$(wildcard wildcard/*.c)										\
				$(wildcard wildcard/utils/*.c)									\
				$(wildcard envp/*.c)									\

FUNCTIONS	=	$(addprefix parser/,				\
				$(addprefix check_syntax/,			\
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

SOURCE		=	$(addprefix source/, $(FUNCTIONS))
OBJECT		=	$(addprefix object/, $(FUNCTIONS:.c=.o))
FOLDER		=	$(sort $(dir object/ $(OBJECT) $(LIBPARSER)))

.SUFFIXES	:
.SUFFIXES	:	.c .o

.PHONY		:	all clean fclean re libft

all			:	libft $(FOLDER) $(NAME)

$(NAME)		:	$(OBJECT) 
				$(CC) $(LDFLAGS) $(CFLAGS) $(OBJECT) $(LIBFT) -o $(NAME)

$(LIBPARSER):	$(OBJECT) $(LIBFT)
				$(CP) $(LIBFT) $(LIBPARSER)
				$(AR) $(ARFLAGS) $(LIBPARSER) $?

$(FOLDER)	:
				$(MKDIR) $@

object/%.o	:	source/%.c $(HEADER)
				$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

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

