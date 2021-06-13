/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:49:27 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/13 19:49:35 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst && *lst && del)
	{
		aux = *lst;
		while (aux)
		{
			ft_lstdelone(aux, del);
			aux = aux->next;
		}
		*lst = 0;
	}
}
