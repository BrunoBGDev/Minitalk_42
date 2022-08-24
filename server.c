/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:13:32 by bbraga            #+#    #+#             */
/*   Updated: 2022/08/24 10:12:57 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	ft_convert_bin(char *str)
{
	unsigned char	chr;
	size_t			len;
	int				temp;

	temp = 1;
	chr = 0;
	len = ft_strlen(str) - 1;
	while (len + 1 != 0)
	{
		chr += temp * (str[len] - '0');
		temp *= 2;
		len--;
	}
	write(1, &chr, 1);
}

static char	*ft_minijoin(char *start, char str)
{
	size_t	index;
	char	*tmp;

	tmp = malloc(ft_strlen(start) + 2);
	if (!tmp)
		return (0);
	index = 0;
	while (start[index] != '\0')
	{
		tmp[index] = start[index];
		index++;
	}
	tmp[index] = str;
	tmp[index + 1] = '\0';
	free(start);
	return (tmp);
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static char			*bits;
	static int			bitcount;

	(void)context;
	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_minijoin(bits, '0');
	else
		bits = ft_minijoin(bits, '1');
	if (bitcount == 8)
	{
		ft_convert_bin(bits);
		free(bits);
		bits = NULL;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %u\n", getpid());
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
