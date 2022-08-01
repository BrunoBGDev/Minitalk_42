/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:04:02 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/10 14:15:01 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	c;
	size_t	s_len;
	char	*str_stack;

	count = 0;
	str_stack = (char *)haystack;
	s_len = ft_strlen(needle);
	if (s_len == 0 || haystack == needle)
		return (str_stack);
	while (str_stack[count] != '\0' && count < len)
	{
		c = 0;
		while (str_stack[count + c] != '\0' && needle[c] != '\0'
			&& str_stack[count + c] == needle[c] && count + c < len)
			c++;
		if (c == s_len)
			return (str_stack + count);
		count++;
	}
	return (0);
}
