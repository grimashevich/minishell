make -C ../..
mkdir bin
cc -Wall -Wextra -Werror test2.c ../../libft.a -o bin/test2.out
bin/test2.out
