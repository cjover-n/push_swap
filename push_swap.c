/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/17 23:23:29 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push		p;
	int flag;

	if (argc < 2)
		return (1);
	flag = 0;
	ft_bzero(&p, sizeof(p));
	p.x = 1;
	while (ft_isdigit(argv[p.x]) && argv[p.x] != '\0')
	{
		p.y++;
		flag = 1;
	}
	while (argv[p.x] && flag == 1)
	{
		printf("%s\n", argv[p.x]);
		p.x++;
	}
	if (flag == 0)
		printf("KK PA TI");
}
