/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:24:34 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/05 20:00:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/time.h>

int	error;

void	check_signal(int signal)
{
	if (signal == SIGSEGV)
	{
		printf("\x1b[33mSEGV\x1b[0m ");
	}
	exit(10);
}

void	*func_check_timeout(void *noting)
{
	sleep(1);
	exit(127);
	return (noting);
}

void	check_timeout(void)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, func_check_timeout, NULL);
	pthread_detach(thread);
}

void	test(char *string)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		exit(1);
	}
	else if (pid == 0)
	{
		check_timeout();
		sleep(2);
		if (ft_strlen(string) == strlen(string))
		{
			exit(0);
		}
		else
		{
			exit(1);
		}
	}
	wait(&status);
	if (WIFEXITED(status) != 0 && WEXITSTATUS(status) == 0)
	{
		write(1, "\x1b[32mOK\x1b[0m ", strlen("\x1b[32mOK\x1b[0m "));
		return ;
	}
	error = 1;
	if (WIFEXITED(status) != 0 && WEXITSTATUS(status) == 127)
		write(1, "\x1b[33mTIMEOUT\x1b[0m ", 17);
	else if (WIFEXITED(status) != 0 && WEXITSTATUS(status) == 10)
		return ;
	else
		write(1, "\x1b[31mKO\x1b[0m ", strlen("\x1b[31mKO\x1b[0m "));
}

void	check_bye(int signal)
{
	if (signal == SIGINT)
	{
		printf("bye\n");
	}
	exit(0);
}

void	launch(void)
{
	signal(SIGSEGV, check_signal);
	signal(SIGINT, check_bye);

	printf("launch Test 1 string ft_strlen\n");
	write(1, ".. ft_strlen ", 15);
	error = 0;
}

void	ending(void)
{
	if (error == 0)
	{
		write(1, "\x1b[s\r\x1b[32mOK\x1b[0m\x1b[u\n", 19);
	}
	else
	{
		write(1, "\x1b[s\r\x1b[31mKO\x1b[0m\x1b[u\n", 19);
	}
}

int	main(void)
{
	launch();
	test(NULL);
	test("1");
	test("22");
	test("333");
	ending();
	return (0);
}
