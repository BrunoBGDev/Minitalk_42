/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:13:23 by bbraga            #+#    #+#             */
/*   Updated: 2022/08/11 19:33:07 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	send_mensage(int pid, unsigned char str)
{
	int	i;

	i <<= 8;
	while (str)
	{
		while (i--)
		{
			if (str & i)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i >>= 1;
		while (i--)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
	}
}

void	sig_handler(char *server_pid, char *str)
{
	int		pid;

	pid = ft_atoi(server_pid);
	while (*str)
	{
		send_mensage(pid, *str);
		str++;
	}
	send_mensage(pid, *str);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("How to use: ./client [server pid] [string to send]\n");
		return (1);
	}
	ft_putstr_fd("Sent: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_printf("\n");
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	sig_handler(argv[1], argv[2]);
	return (0);
}
