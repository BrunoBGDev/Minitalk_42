/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:21:44 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/10 13:41:38 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

static void	ft_ptchar_fd(char c, int fld)
{
	write(fld, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -1 * n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_ptchar_fd((n % 10) + '0', fd);
}
