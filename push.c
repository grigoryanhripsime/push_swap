/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:31:40 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 13:32:16 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	(*b) = (*b)-> next;
	if (!(*a))
		tmp -> next = 0;
	else
		tmp -> next = (*a);
	(*a) = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	push(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	write(1, "pb\n", 3);
	push(b, a);
}
