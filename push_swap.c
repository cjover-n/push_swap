/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/27 18:31:24 by cjover-n         ###   ########.fr       */
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

int	generate_stacks(char **argv, int argc, t_stack *stack)
{
	int			i;
	t_element	*current;

	i = 1;
	current = NULL;
	while (i < argc)
	{
		current = new_lst(ft_atoi(argv[i]));
		if (i == 1)
			stack->top = current;
		if (i == argc - 1)
			stack->end = current;
		//current = current->next;
		i++;
	}
	return (1);
}

void	init(t_push *push)
{
	push->stack_a.top = NULL;
	push->stack_a.end = NULL;
	push->stack_b.top = NULL;
	push->stack_b.end = NULL;
	push->x = 0;
	push->y = 0;
}

int	check_args(char **argv)
{
	/*
		TODO: Hacer mas checks de argv...
	*/
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *stack_a)
{
	t_element *current;
	int i;

	i = 0;
	current = stack_a->top;
	while (current != NULL)
	{
		printf("[%i]\n", current->content);
		current = current->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_push 		push;

	if (argc == 1)
		return (1);
	init(&push);
	if(check_args(argv))
		generate_stacks(argv, argc, &push.stack_a);
	else
	{
		ft_putstr_fd("Error: argumento inválido.\n", 1);
		return (1);
	}
	print_stack(&push.stack_a);
	return (0);
}
