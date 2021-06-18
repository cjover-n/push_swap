/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/18 21:47:49 by cjover-n         ###   ########.fr       */
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
	t_list *current;
	int j = 0;

	current = push->a;
	while (current->next)
	{
		if (current->content > current->next->content)
		{
			j++;
			current = current->next;
		}
		else
			return 0;
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
	t_list *current;
    
	int i;

	if (argc == 1)
		return (1);
	i = 1;
	push.b = NULL;
	push.a = NULL;
	current = push.a;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
		ft_lstclear(&current, free);
		current = ft_lstnew(argv[i]);
		printf("[%s]\n", current->content);
		current = current->next;
		i++;
	}
	if (order(&push) == 0)
		printf("order es cero\n");
	return (0);
}
