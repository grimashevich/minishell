# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:02:56 by ccamie            #+#    #+#              #
#    Updated: 2022/05/24 17:34:28 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

. script/header.sh

function runTests {
	readTests $pathToTestFile
	printf "\x1b[40m ${FUNCTIONS[$i]} \x1b[0m\n"
	for j in ${!TESTS[*]}
	do
		test
		testLeak
		testAddress
		printAll
	done
	removeCurrentTest
	removeBin
}

for i in ${!FUNCTIONS[*]}
do
	initPaths "${FUNCTIONS[$i]}"
	compileAllFiles
	runTests
done
