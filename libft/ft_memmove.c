/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:30:27 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/14 11:45:21 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	count;

	count = 0;
	if (!dst && !src)
		return (0);
	if (((unsigned char *)src) < ((unsigned char *)dst))
	{
		while (len)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (count < len)
		{
			((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
			count++;
		}
	}
	return ((unsigned char *)dst);
}
