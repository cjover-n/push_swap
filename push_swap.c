/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:18 by cjover-n          #+#    #+#             */
/*   Updated: 2021/05/25 22:28:37 by cjover-n         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	int i;

	if (argc < 2)
		return (1);
	char **arr = ft_split(argv[1], ' ');
	i = 0;
	b = NULL;
	while (arr[i] != 0)
	{
		a = ft_lstnew(arr[i]);
		if (!ft_isnum(a->content))
			return(0);
		printf("[%s]\n", a->content);
		i++;
	}
}
