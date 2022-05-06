make -C ../..
mkdir bin
cc -Wall -Wextra -Werror test_ft_strlen.c ../../libft.a -o bin/test_ft_strlen.out
bin/test_ft_strlen.out
