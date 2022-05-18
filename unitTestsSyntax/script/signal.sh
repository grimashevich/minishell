# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    signal.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 23:59:47 by ccamie            #+#    #+#              #
#    Updated: 2022/05/16 14:08:15 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function checkSignal {
	printf "\n\x1b[45m Forced completion of the test \x1b[0m\x1b[?25h\n"
	exit
}

trap "checkSignal" 2
