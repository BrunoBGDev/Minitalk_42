/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:24:55 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/14 11:45:16 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	count;

	if (!dst && !src)
		return (NULL);
	count = 0;
	while (n > 0)
	{
		((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
		count++;
		n--;
	}
	return (dst);
}
