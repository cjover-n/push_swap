/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:19:53 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/16 17:13:53 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*cpy;
	t_list	*nxt;

	if (lst && f)
	{
		nxt = ft_lstnew(lst->content);
		res = nxt;
		res->content = f(res->content);
		if (!res->content)
			del(res->content);
		while (lst->next != NULL)
		{
			lst = lst->next;
			cpy = ft_lstnew(lst->content);
			cpy->content = f(cpy->content);
			if (!cpy->content)
				del(cpy->content);
			nxt->next = cpy;
			nxt = cpy;
		}
		return (res);
	}
	return (0);
}
