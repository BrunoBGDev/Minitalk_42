/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:13:23 by bbraga            #+#    #+#             */
/*   Updated: 2022/08/21 22:24:59 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("%i\n", received);
		exit(0);
	}
}

static void	send_message(int pid, char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		index++;
		usleep(500);
	}
}

static int	check_pid(char *str)
{
	int		index;

	while (str[index] != '\0')
	{
		if (ft_isdigit(str[index]) == 0)
		{
			ft_printf("ERROR:Pid require only numbers!\n");
			return (1);
			break ;
		}
		else
			index++;
	}
	return (0);
}

static char	*str_to_bin(char *str, size_t count, size_t index)
{
	char	*rtn;
	int		chr;
	int		bit;

	count = ft_strlen(str);
	rtn = ft_calloc(count * 8 + 1, sizeof(char));
	if (!rtn)
		return (0);
	while (count + 1 != 0)
	{
		chr = str[count - 1];
		bit = 8;
		while (bit > 0)
		{
			if (chr % 2 == 1)
				rtn[ft_strlen(str) * 8 - index - 1] = '1';
			else
				rtn[ft_strlen(str) * 8 - index - 1] = '0';
			chr /= 2;
			index++;
			bit--;
		}
		count--;
	}
	return (rtn);
}

int	main(int argc, char **argv)
{
	char	*bin;
	int		pid;

	if (check_pid(argv[1]) == 1)
		return (1);
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("ERROR:How to use: ./client [server pid] [string to send]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	bin = str_to_bin(argv[2], 0, 0);
	ft_printf("Sent: %i\n", ft_strlen(argv[2]));
	ft_printf("Received: ");
	signal(SIGUSR2, action);
	send_message(pid, bin);
	return (0);
}
