# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:40:32 by ccamie            #+#    #+#              #
#    Updated: 2022/05/11 20:24:38 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

trap "forced_completion_of_the_test" 2

function forced_completion_of_the_test {
	printf "\n\x1b[45m Forced completion of the test \x1b[0m\x1b[?25h\n"
	remove_file $FUNCTION
	rm .trash
	exit
}

function create_test {
	printf "Test name: \x1b[32m"
	read TEST_NEW
	printf "\x1b[0m"
	mkdir $TEST_NEW 2> .trash
	if [[ $? -eq 0 ]]
	then
		printf "Сreate a test: \x1b[32m%s\x1b[0m\n" $TEST_NEW
		cp pattern/* $TEST_NEW/
		printf "\n%s" $TEST_NEW >> list_of_functions.txt
	else
		printf "Such a test already exists: \x1b[31m%s\x1b[0m\n" $TEST_NEW
	fi
}

function execute_makefile {
	if [[ -z $1    ]]
	then
		make -C .. && make -C libtest
	fi
	if [[ $1 == "re" ]]
	then
		make re -C .. && make re -C libtest
	fi
	if [[ $1 == "clean" ]]
	then
		make clean -C .. && make clean -C libtest
	fi
	if [[ $1 == "fclean" ]]
	then
		make fclean -C .. && make fclean -C libtest
	fi
}

if [[ $1 == "new" ]]
then
	create_test
	exit
fi

if [[ $1 == "make" ]]
then
	execute_makefile $2
	exit
fi

if [[ -n $1   ]]
then
	FUNCTIONS[0]=$1
else
	index=0
	for FUNCTION in $(cat list_of_functions.txt)
	do
		FUNCTIONS[$index]=$FUNCTION
		index=$(($index+1))
	done
fi

function compile_files {
	local LIBPARSER=../library/libparser.a
	local LIBTEST=libtest/library/libtest.a
	local CPPFLAGS="-I libtest/include -I ../include -I ../libft/include"
	local SOURCE="$CPPFLAGS $LIBTEST $LIBPARSER $FUNCTION/parser.c $FUNCTION/remove_all.c"
	local CFLAGS=-fsanitize=address
	local MAIN_TEST=main/test.c
	local MAIN_TEST_LEAK=main/test_leak.c
	local MAIN_TEST_ADDRESS=main/test_address.c

	cc         $SOURCE $MAIN_TEST         $FUNCTION/test.c          -o $FUNCTION/test 2> .trash
	if [[ $? -ne 0 ]]
	then
		printf "\x1b[40m $FUNCTION \x1b[0m\n\t\t\x1b[31mDOES NOT COMPILED\x1b[0m\n\n"
		return 1
	fi
	cc         $SOURCE $MAIN_TEST_LEAK    $FUNCTION/test_leak.c     -o $FUNCTION/test_leak 2> .trash
	if [[ $? -ne 0 ]]
	then
		printf "\x1b[40m $FUNCTION \x1b[0m\n\t\t\x1b[31mDOES NOT COMPILED\x1b[0m\n\n"
		return 1
	fi
	cc $CFLAGS $SOURCE $MAIN_TEST_ADDRESS $FUNCTION/test_address.c  -o $FUNCTION/test_address 2> .trash
	if [[ $? -ne 0 ]]
	then
		printf "\x1b[40m $FUNCTION \x1b[0m\n\t\t\x1b[31mDOES NOT COMPILED\x1b[0m\n\n"
		return 1
	fi
	return 0
}

function basic_test {
	$FUNCTION/test $ARGV $FUNCTION/test_output.txt 2> .trash > $FUNCTION/test.tmp
	return $?
}

function test_leak {
	local LEAK="leaks -quiet --atExit -- "
	local STATUS=$($LEAK $FUNCTION/test_leak $ARGV $FUNCTION/test_output.txt 2> .trash | head -3 | grep -c ": 0 leaks for 0 total leaked bytes.")
	
	if [[ $STATUS -eq 1 ]]
	then
		printf "\x1b[32mLEAK \x1b[0m" >> $FUNCTION/test.tmp
	else
		printf "\x1b[31mLEAK \x1b[0m" >> $FUNCTION/test.tmp
	fi
}

function test_address {
	$FUNCTION/test_address $ARGV $FUNCTION/test_output.txt 2> .trash >> $FUNCTION/test.tmp
}

function advanced_test {
	if [[ $EXIT_CODE -eq 0 ]] || [[ $EXIT_CODE -eq 1 ]]
	then
		test_leak $FUNCTION $ARGV
		test_address $FUNCTION $ARGV
	fi
}

function function_test {
	printf "\x1b[40m $FUNCTION \x1b[0m\n\t\t"
	for ARGV in $(cat -t $FUNCTION/list_of_tests.txt)
	do
		basic_test $FUNCTION $ARGV
		local EXIT_CODE=$?
		advanced_test $EXIT_CODE $FUNCTION $ARGV
		cat $FUNCTION/test.tmp
		printf "\n\t\t"
	done
	printf "\n"
}

function remove_file {
	rm $FUNCTION/test
	rm $FUNCTION/test_leak
	rm $FUNCTION/test_address
	rm $FUNCTION/test_output.txt
	rm $FUNCTION/test.tmp
}

printf "\x1b[?25l"

for FUNCTION in ${FUNCTIONS[*]}
do
	compile_files $FUNCTION
	if [[ $? -ne 0 ]]
	then
		continue
	fi
	function_test $FUNCTION
	remove_file $FUNCTION
done

rm .trash
printf "\x1b[?25h"
