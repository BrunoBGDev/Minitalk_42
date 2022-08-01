/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:34:34 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/10 13:44:50 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	rst_len;
	char	*join;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	rst_len = s1_len + s2_len + 1;
	join = malloc(sizeof(char) * rst_len);
	if (!join)
		return (0);
	ft_memmove(join, s1, s1_len);
	ft_memmove(join + s1_len, s2, s2_len);
	join[rst_len - 1] = '\0';
	return (join);
}
