SHELL		=	/bin/sh

NAME		=	minishell

LIBPARSER	=	library/libparser.a

LIBFT		=	libft/library/libft.a

CC			=	cc

CFLAGS		=	-g

CPPFLAGS	=	-Wall -Wextra -Werror	\
				-I libft/include		\
				-I include

AR			=	ar
ARFLAGS		=	crs

CP			=	cp

MKDIR		=	mkdir -p
RMDIR		=	rm -rf
RM			=	rm -f

HEADER		=	libft/include/libft.h	\
				$(addprefix include/,	\
				minishell.h				\
				parser.h				\
				)

FUNCTIONS	=	$(addprefix parser/,				\
				$(addprefix check_syntax/,			\
					check_quotation_mark_syntax.c	\
					check_syntax_of_parentheses.c	\
					check_syntax_of_the_operators.c	\
					check_syntax_of_the_redirect.c	\
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

$(NAME)		:	$(LIBPARSER)
				$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBPARSER) source/test1.c -o $(NAME)

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
