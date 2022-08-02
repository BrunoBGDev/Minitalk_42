/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:47:17 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/20 14:25:50 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_numbers(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	int		getnbr;
	char	*nb;

	getnbr = ft_get_numbers(n);
	nb = (char *)malloc(sizeof(char) * (getnbr + 1));
	if (!nb)
		return (0);
	nb[getnbr] = '\0';
	while (n != 0)
	{
		nb[getnbr - 1] = n % 10 + 48;
		n /= 10;
		getnbr--;
	}
	return (nb);
}

int	ft_unsigned(unsigned int n)
{
	int		rtn;
	char	*nb;

	rtn = 0;
	if (n == 0)
		rtn += write(1, "0", 1);
	else
	{
		nb = ft_uitoa(n);
		rtn += ft_print_str(nb);
		free(nb);
	}
	return (rtn);
}
