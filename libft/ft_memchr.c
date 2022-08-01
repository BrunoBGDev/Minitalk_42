/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:13:48 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/10 13:36:52 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*str;
	unsigned char	chr;

	chr = (unsigned char) c;
	str = (unsigned char *) s;
	count = 0;
	while (count < n)
	{
		if (*str == chr)
			return (str);
		str++;
		count++;
	}
	return (0);
}
