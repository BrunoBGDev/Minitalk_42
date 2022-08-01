/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:09:12 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/14 11:46:09 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	src_len;

	count = 0;
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src[count] != '\0' && count < dstsize - 1)
	{
		dst[count] = src[count];
		count++;
	}
	if (count < dstsize)
		dst[count] = '\0';
	while (src[count] != 0)
		count++;
	return (src_len);
}
