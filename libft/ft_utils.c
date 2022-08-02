/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:23:32 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/20 13:21:19 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_ptstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
}

int	ft_print_str(char *str)
{
	int	count;

	if (!str)
	{
		ft_ptstr("(null)");
		return (6);
	}
	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnb(int n)
{
	int		nb;
	char	*convert;

	nb = 0;
	convert = ft_itoa_printf(n);
	nb = ft_print_str(convert);
	free(convert);
	return (nb);
}
