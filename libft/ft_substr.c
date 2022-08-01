/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:29:01 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/14 10:08:42 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rst;
	size_t	count;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	count = len + 1;
	rst = (char *)malloc(count * sizeof(char));
	if (!rst)
		return (0);
	ft_memcpy(rst, s + start, len);
	rst[len] = '\0';
	return (rst);
}
