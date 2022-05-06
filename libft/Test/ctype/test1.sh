make -C ../..
mkdir bin
cc -Wall -Wextra -Werror test1.c ../../libft.a -o bin/test1.out
bin/test1.out
