/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:30:32 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/19 23:33:18 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_ptchr(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstrl(char *str, int *len)
{
	int	count;

	count = 0;
	while (str[count])
	{
		ft_ptchr(str[count], len);
		count++;
	}
}
