# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 15:56:58 by ccamie            #+#    #+#              #
#    Updated: 2022/05/18 17:09:21 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

LEAKS="leaks -quiet --atExit -- "

function test {
	$pathToExecutableFile $dir "${TESTS[$j]}"
	exitCode=$?
	if [[ $exitCode -ne 0 ]] && [[ $exitCode -ne 1 ]]
	then
		print $exitCode
		echo
		cat $pathToLogFile
		rm -f $pathToLogFile
		continue
	fi
}

function testLeak {
	local STATUS=$($LEAKS $pathToExecutableFileLeak $dir "${TESTS[$j]}" 2> wtf | head -3 | grep -c ": 0 leaks for 0 total leaked bytes.")
	if [[ $STATUS -eq 0 ]]
	then
			exitCodeLeak=1
		else
			exitCodeLeak=0
	fi
}

function testAddress {
	$pathToExecutableFileAddress $dir "${TESTS[$j]}" 2> wtf
	exitCodeAddress=$?
}
