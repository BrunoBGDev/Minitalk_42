/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:13:32 by bbraga            #+#    #+#             */
/*   Updated: 2022/08/23 22:14:45 by bbraga           ###   ########.fr       */
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

static void	ft_action(int sig)
{
	static char			*bin;
	static int			bit;

	bit++;
	if (bin == NULL)
	{
		bin = ft_strdup("");
		bit = 1;
	}
	if (sig == SIGUSR2)
		bin = ft_minijoin(bin, '0');
	else
		bin = ft_minijoin(bin, '1');
	if (bit == 8)
	{
		ft_convert_bin(bin);
		free(bin);
		bin = NULL;
	}
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	while (1)
		pause();
	return (0);
}
