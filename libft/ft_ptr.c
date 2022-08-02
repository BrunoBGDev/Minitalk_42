/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:14:28 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/20 14:21:44 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_hex(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_putptr_hex(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putptr_hex(n / 16);
		ft_putptr_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_ptr(unsigned long long ptr)
{
	int	rtn;

	rtn = 0;
	rtn += write(1, "0x", 2);
	if (ptr == 0)
		rtn += write(1, "0", 1);
	else
	{
		ft_putptr_hex(ptr);
		rtn += ft_ptr_hex(ptr);
	}
	return (rtn);
}
