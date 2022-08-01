/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:19:44 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/10 13:45:53 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*source;
	size_t	size;
	size_t	dst_len;

	dest = dst;
	source = (char *)src;
	size = dstsize;
	while (size-- != 0 && *dest != '\0')
		dest++;
	dst_len = dest - dst;
	size = dstsize - dst_len;
	if (size == 0)
		return (dst_len + ft_strlen(src));
	while (*source != '\0')
	{
		if (size != 1)
		{
			*dest++ = *source;
			size--;
		}
		source++;
	}
	*dest = '\0';
	return (dst_len + (source - src));
}
