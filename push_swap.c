/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/10 22:02:16 by cjover-n         ###   ########.fr       */
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

/*
Getionar primero los parámetros pasados por zsh, no por bash
Es decir, los parámetros uno por uno
*/

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_list		*current;
	int i;

	if (argc == 1)
		return (1);
	i = 1;
	b = NULL;
	a = NULL;
	current = a;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
		//TODO --> Hacer free primero con lstclear
		current = ft_lstnew(argv[i]);
		printf("[%s]\n", current->content);
		current = current->next;
		i++;
	}
	return (0);
}
