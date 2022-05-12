
NAME		=	minishelltest1

HEADER		=	libft.h

LIBFT		=	../../libft/libft.a

CC			=	cc
# CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		+=	-fsanitize=address
# CFLAGS		+=	-fsanitize=undefined
# CFLAGS		+= -g
RM			=	rm -f

SOURCE		=	test1.c	\
				../check_syntax/check_quotation_mark_syntax.c	\
				../check_syntax/check_syntax_of_parentheses.c	\
				../check_syntax/check_syntax_of_the_operators.c	\
				../check_syntax/check_syntax.c					\
				../print/print_diagram.c	\
				../print/print_tree.c		\
				../count_the_number_of_operators.c	\
				../get_command.c					\
				../get_container.c					\
				../give_a_line_before_operator.c	\
				../parser.c							\
				../remove_insignificant.c			\

OBJECT		=	$(SOURCE:.c=.o)

.PHONY		:	all clean fclean re libft

all			:	libft $(NAME)

$(NAME)		:	$(OBJECT) 
				$(CC) $(CFLAGS) $(OBJECT) $(LIBFT) -o $(NAME)

%.o			:	%.c $(LIBFT)
				$(CC) $(CFLAGS) -c $< -o $@

libft		:
				make -C ../../libft

clean		:
				$(RM) $(OBJECT)
				make -C ../../libft clean

fclean		:
				$(RM) $(OBJECT)
				$(RM) $(NAME)
				make -C ../../libft fclean

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











