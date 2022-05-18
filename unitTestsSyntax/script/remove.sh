# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    remove.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 23:59:48 by ccamie            #+#    #+#              #
#    Updated: 2022/05/18 00:49:33 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function removeBin {
	rm -f $pathToExecutableFile
	rm -f $pathToExecutableFileLeak
	rm -f $pathToExecutableFileAddress
}

function removeCurrentTest {
	rm -f $pathToEstimationFile
	rm -f $pathToLogFile
	rm -f $pathToOutputFile
}
