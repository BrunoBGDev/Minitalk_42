/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:22:08 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/13 10:08:01 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	count;
	long	nbr;
	long	ngnbr;

	count = 0;
	nbr = 0;
	ngnbr = 0;
	while (str[count] != '\0' && (str[count] == 32
			|| str[count] == '\t' || str[count] == '\n'
			|| str[count] == '\r' || str[count] == '\v'
			|| str[count] == '\f'))
		count++;
	if (str[count] != '\0' && str[count] == '-')
	{
		ngnbr = 1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] != '\0' && ft_isdigit(str[count]))
		nbr = nbr * 10 + (str[count++] - '0');
	if (ngnbr == 1)
		return (-nbr);
	return (nbr);
}
