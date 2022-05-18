# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    readFile.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 23:59:49 by ccamie            #+#    #+#              #
#    Updated: 2022/05/16 14:46:30 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function readFunctions {
	FUNCTIONS=()
	while IFS="" read -r FUNCTION || [ -n "$FUNCTION" ]
	do
		FUNCTIONS+=("$FUNCTION")
	done < $1
}

function readTests {
	TESTS=()
	while IFS="" read -r TEST || [ -n "$TEST" ]
	do
		TESTS+=("$TEST")
	done < $1
}

readFunctions "functions.txt"
