/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:28:53 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/14 12:04:18 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != (char)c)
	{
		if (!s[count++])
			return (0);
	}
	return ((char *)&s[count]);
}
