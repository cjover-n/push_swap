/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:56:35 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/25 20:54:40 by cjover-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./Libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_element
{
	struct s_element	*next;
	int					content;
}						t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*end;
}				t_stack;

typedef struct s_push
{
	int			x;
	int			y;
	t_stack		stack_a;
	t_stack		stack_b;
}				t_push;

t_element *new_lst(int content);

#endif
