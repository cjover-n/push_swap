/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/19 22:48:57 by cjover-n         ###   ########.fr       */
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

void		compare_two(t_list *list1, t_list *list2)
{
	if (list1 && list2)
	{
		if (ft_atoi(list1->content) > ft_atoi(list2->content))
		{
			printf("El primer elemento es mayor que el segundo");
		}
		else
		{
			printf("El primer elemento es menor que el segundo");
		}
	}
}

void cosa(t_list *list)
{
	if (list->next)
		cosa(list->next);
	free(list);
}

/*
Getionar primero los parámetros pasados por zsh, no por bash
Es decir, los parámetros uno por uno
*/

int	main(int argc, char **argv)
{
	t_push 		push;
	t_list 	*current;
    
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
		if (!push.a)
		{
			current = ft_lstnew(argv[i]);
			push.a = current;
			printf("[%s]\n", current->content);
		}
		else
		{
			current = ft_lstnew(argv[i]);
			ft_lstadd_back(&push.a, current);
			printf("[%s]\n", current->content);
		}
		i++;
	}
	compare_two(push.a, push.a->next);
	cosa(push.a);
	system("leaks push_swap");
	return (0);
}
