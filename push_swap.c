/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/18 22:00:03 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push		p;
	//t_list		*a;
	//t_list		*b;
	int	num;

	if (argc < 2)
		return (1);
	ft_bzero(&p, sizeof(p));
	while (--argc > 0)
	{
		if (!ft_isdigit(ft_atoi(argv[argc])))
			return (0);
		num  = ft_atoi(argv[argc]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
	}
	while(num)
		printf("%i\n", num);
}
