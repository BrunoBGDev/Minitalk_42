/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:20:22 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/09 12:41:11 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *s, char c)
{
	int		i;
	int		j;
	char	end;

	i = 0;
	j = 0;
	end = c;
	while (s[i] != '\0')
	{
		if (end == c && s[i] != c)
			j++;
		end = s[i];
		i++;
	}
	return (j);
}

static char	*ft_minitrim(const char *str, int start, int end)
{
	char	*chr;
	size_t	count;

	count = 0;
	chr = malloc(sizeof(char) * (end - start) + 1);
	if (!chr)
		return (0);
	while (start < end)
	{
		chr[count] = str[start];
		count++;
		start++;
	}
	chr[count] = '\0';
	return (chr);
}

char	**ft_split(const char *s, char c)
{
	int		array;
	char	**rst;
	size_t	count;
	size_t	i;

	rst = (char **)malloc(((ft_check(s, c)) + 1) * sizeof(*rst));
	if (!rst)
		return (0);
	count = 0;
	i = 0;
	array = -1;
	while (count <= ft_strlen(s))
	{
		if (s[count] != c && array < 0)
			array = count;
		else if ((s[count] == c || count == ft_strlen((char *)s)) && array >= 0)
		{
			rst[i++] = ft_minitrim(s, array, count);
			array = -1;
		}
		count++;
	}
	rst[i] = 0;
	return (rst);
}
