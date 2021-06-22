/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/22 21:37:54 by cjover-n         ###   ########.fr       */
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

static char	*next_num(t_pswap *pswap, char *numstart, char *numbuf, \
size_t *numlen)
{
	numstart = ft_skipspaces(numstart);
	if (*numstart == '-' || *numstart == '+')
		numbuf[0] = *numstart++;
	if (!ft_isdigit(*numstart))
		exit_failure("Error", pswap);
	*numlen = 0;
	while (*numstart == '0' && ft_isdigit(*(numstart + 1)))
		numstart++;
	while (ft_isdigit(numstart[*numlen]))
		(*numlen)++;
	if (!ft_isspace(numstart[*numlen]) && numstart[*numlen])
		exit_failure("Error", pswap);
	else if (*numlen > 10 || (*numlen == 10 \
	 && exceeded_max_int(numstart, numbuf[0])))
		exit_failure("Error", pswap);
	return (numstart);
}

static char	*generate_stack_a(t_push *push, char *num)
{
	t_list		*new;
	char		numbuf[12];
	size_t		numlen;

	numbuf[11] = 0;//11 es el número máximo de caracteres que puede tener un número de la lista contando con el - y el \0 del final
	ft_memset(numbuf, '0', 11);//rellena de ceros
	num = next_num(push, num, numbuf, &numlen);
	while (&num[numlen] > num)
		numbuf[11 - numlen--] = *num++;
	new = ft_lstnew(ft_calloc(1, sizeof(int)));
	*(int *)new->content = ft_atoi(numbuf);
	if (!push->stack_a.stack)
		push->stack_a.stack = new;
	else
		ft_lstadd_back(&push->stack_a.stack, new);
	return (num);
}

int	generate_stacks(char **argv, t_push *push)
{
	char		**args;
	char		*num;

	(void)push;
	args = &argv[1];
	while (*args)
	{
		num = *args++;
		while (*num)
		{
			num = generate_stack_a(push, num);
			printf("%s", num);
		}	
	}
	push->stack_b.stack = NULL;
	return (1);
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
	push.stack_a_clone = NULL;
	current = push.stack_a_clone;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
		if (!push.stack_a_clone)
		{
			current = ft_lstnew(argv[i]);
			push.stack_a_clone = current;
			printf("[%s]\n", current->content);
		}
		else
		{
			current = ft_lstnew(argv[i]);
			ft_lstadd_back(&push.stack_a_clone, current);
			printf("[%s]\n", current->content);
		}
		i++;
	}
	compare_two(push.stack_a_clone, push.stack_a_clone->next);
	generate_stacks(argv, &push);
	cosa(push.stack_a_clone);
	return (0);
}
