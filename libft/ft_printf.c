/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:08:30 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/20 14:27:01 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, const char format)
{
	int	rtn;

	rtn = 0;
	if (format == 'c')
		rtn += ft_putchr(va_arg(args, int));
	else if (format == 's')
		rtn += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		rtn += ft_putnb(va_arg(args, int));
	else if (format == 'p')
		rtn += ft_ptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		rtn += ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		rtn += ft_hex_format(va_arg(args, unsigned int), format);
	else if (format == '%')
		rtn = write(1, "%", 1);
	return (rtn);
}

int	ft_printf(const char *str, ...)
{	
	va_list	args;
	int		count;
	int		len;

	count = 0;
	len = 0;
	va_start(args, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			len += ft_check_format(args, str[count + 1]);
			count++;
		}
		else
			len += ft_putchr(str[count]);
		count++;
	}
	va_end(args);
	return (len);
}
