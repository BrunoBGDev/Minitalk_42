/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:18:16 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/07 19:37:47 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_gen;
	t_list	*nw_list;

	if (!lst || !f)
		return (0);
	lst_gen = ft_lstnew(f(lst->content));
	nw_list = lst_gen;
	lst = lst->next;
	while (lst)
	{
		lst_gen ->next = ft_lstnew(f(lst->content));
		if (!lst_gen->next)
		{
			ft_lstclear(&nw_list, del);
			return (0);
		}
		lst_gen = lst_gen->next;
		lst = lst->next;
	}
	lst_gen->next = 0;
	return (nw_list);
}
