/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:37:35 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/14 12:06:40 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*ptr;
	char	chr;

	chr = (char) c;
	count = 0;
	ptr = 0;
	while (s[count] != '\0')
	{
		if (s[count] == chr)
			ptr = (char *)(s + count);
		count++;
	}
	if (s[count] == chr)
	{
		ptr = (char *)(s + count);
	}
	return (ptr);
}
