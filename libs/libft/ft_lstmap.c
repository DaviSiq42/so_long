/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:54:36 by davioliv          #+#    #+#             */
/*   Updated: 2023/06/15 14:08:32 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_cont;

	if (!lst || !f)
		return (NULL);
	new_cont = ft_lstnew(f(lst->content));
	if (!new_cont)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_list = new_cont;
	lst = lst->next;
	while (lst)
	{
		new_cont = ft_lstnew(f(lst->content));
		if (!new_list)
		{
			ft_lstclear(&new_list, del);
			ft_lstclear(&lst, del);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_cont);
	}
	return (new_list);
}
