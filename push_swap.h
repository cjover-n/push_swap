/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjover-n <cjover-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:56:35 by cjover-n          #+#    #+#             */
/*   Updated: 2021/06/22 20:35:56 by cjover-n         ###   ########.fr       */
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
	t_list		*stack;
}				t_stack;

typedef struct s_push
{
	int			x;
	int			y;
	t_list		*stack_a_clone;
	t_list		*b;
	t_stack		stack_a;
	t_stack		stack_b;
}				t_push;



#endif
