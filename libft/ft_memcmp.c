/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:31:41 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/10 13:38:01 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				count;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	count = 0;
	while (count < n)
	{
		if (str1[count] != str2[count])
			return (str1[count] - str2[count]);
		count++;
	}
	return (0);
}
