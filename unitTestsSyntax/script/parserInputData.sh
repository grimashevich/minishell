# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parserInputData.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 23:59:54 by ccamie            #+#    #+#              #
#    Updated: 2022/05/16 14:06:00 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function parserInputData {
	if   [[ -z $1    ]]
	then
		return
	fi
	exit
}

parserInputData $1
