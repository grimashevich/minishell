# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 23:59:55 by ccamie            #+#    #+#              #
#    Updated: 2022/05/17 15:53:49 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function initPaths {
	dir="$1"
	source="$dir/compare.c		\
			$dir/execute.c		\
			$dir/parser.c		\
			$dir/print.c		\
			$dir/remove_all.c"
	pathToExecutableFile="$dir/bin"
	pathToExecutableFileLeak="$dir/binLeak"
	pathToExecutableFileAddress="$dir/binAddress"
	pathToTestFile="$dir/tests.txt"
	pathToLogFile="$dir/log.tmp"
	pathToOutputFile="$dir/output.tmp"
}
