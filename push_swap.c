/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/13 20:26:02 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnum(char *str)
{
	int	count;

	count = 0;
	if ((str[count] == '+' || str[count] == '-') && ft_strlen(str) > 1)
		count++;
	while (str[count] != '\0')
	{
		if (ft_isdigit(str[count]) == 0)
			return (0);
		count++;
	}
	return (1);
}

int		order(t_push *push)
{
	int j = 0;

	while (push->current->next)
	{
		if (push->current->content > push->current->next)
		{
			j++;
			push->current->content = push->current->next;
		}
	}
	return (j);
}

/*
Getionar primero los parámetros pasados por zsh, no por bash
Es decir, los parámetros uno por uno
*/

int	main(int argc, char **argv)
{
	t_push push;
	int i;

	if (argc == 1)
		return (1);
	i = 1;
	push.b = NULL;
	push.a = NULL;
	push.current = push.a;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
		ft_lstclear(&push.current, free);
		push.current = ft_lstnew(argv[i]);
		printf("[%s]\n", push.current->content);
		push.current = push.current->next;
		i++;
	}
	if (order(&push) == 0)
		printf("order es cero\n");
	return (0);
}
