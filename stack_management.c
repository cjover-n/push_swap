/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:44:30 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/27 18:32:45 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element *new_lst(int content)
{
	t_element *new;

	new = (t_element *)malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}