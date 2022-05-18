# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 23:59:30 by ccamie            #+#    #+#              #
#    Updated: 2022/05/18 01:58:54 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

CC="cc"

CPPFLAGS="	-Wall		\
			-Wextra		\
			-Werror		\
			-I include"

CFLAGS="-fsanitize=address"

library="library/libunit.a"

main="main/main.c"
mainLeak="main/mainLeak.c"

function compileAllFiles {
	$CC $CPPFLAGS $library $main $source -o $pathToExecutableFile
	if [[ $? -ne 0 ]]
	then
		printf "\x1b[40m ${FUNCTIONS[$i]} \x1b[0m\n\t\t\x1b[1m\x1b[31mDOES NOT COMPILE\x1b[0m\n"
		continue
	fi

	# $CC $CPPFLAGS $library $mainLeak $source -o $pathToExecutableFileLeak
	# if [[ $? -ne 0 ]]
	# then
	# 	printf "\x1b[40m ${FUNCTIONS[$i]} \x1b[0m\n\t\t\x1b[1m\x1b[31mDOES NOT COMPILE\x1b[0m\n"
	# 	continue
	# fi

	# $CC $CPPFLAGS $CFLAGS $library $mainLeak $source -o $pathToExecutableFileAddress
	# if [[ $? -ne 0 ]]
	# then
	# 	printf "\x1b[40m ${FUNCTIONS[$i]} \x1b[0m\n\t\t\x1b[1m\x1b[31mDOES NOT COMPILE\x1b[0m\n"
	# 	continue
	# fi
}
