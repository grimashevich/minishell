# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 23:59:50 by ccamie            #+#    #+#              #
#    Updated: 2022/05/17 16:13:35 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function print {
	if [[ $1 -eq 2 ]]
	then
		printf "\t\t\x1b[1m\x1b[33m  TEST ERROR\x1b[0m"
	fi

	if [[ $1 -eq 3 ]]
	then
		printf "\t\t\x1b[1m\x1b[31m  TIMEOUT\x1b[0m"
	fi

	if [[ $1 -eq 6 ]]
	then
		printf "\t\t\x1b[1m\x1b[33m  ABORT\x1b[0m"
	fi

	if [[ $1 -eq 10 ]]
	then
		printf "\t\t\x1b[1m\x1b[33m  BUS ERROR\x1b[0m"
	fi

	if [[ $1 -eq 11 ]]
	then
		printf "\t\t\x1b[1m\x1b[33m  SEGMENTATION FAULT\x1b[0m"
	fi
}

function printAll {
	if [[ $exitCode -ne 0 ]]
	then
		echo
		printf "\t\t\x1b[1m\x1b[31m  OK\x1b[0m" 
	elif [[ $exitCodeLeak -ne 0 ]] ||  [[ $exitCodeAddress -ne 0 ]]
	then
		echo
		printf "\t\t\x1b[1m\x1b[33m  OK\x1b[0m"
	else
		printf "\t\t\x1b[1m\x1b[32m  OK\x1b[0m"
	fi

	if [[ $exitCodeLeak -ne 0 ]]
	then
		printf "\x1b[1m\x1b[31m LEAK\x1b[0m"
	fi

	if [[ $exitCodeAddress -ne 0 ]]
	then
		printf "\x1b[1m\x1b[31m ADDRESS\x1b[0m"
	fi
	echo
	if [[ $exitCode -ne 0 ]] || [[ $exitCodeLeak -ne 0 ]] || [[ $exitCodeAddress -ne 0 ]]
	then
		cat $pathToLogFile
		rm -f $pathToLogFile
	fi
}
