/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:52:31 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/19 22:53:21 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** He sido secuestrado de libft de Miki
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = (void *)content;
		tmp->next = NULL;
	}
	return (tmp);
}
