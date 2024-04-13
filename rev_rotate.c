/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:32:23 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 16:58:36 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a == NULL || a == NULL)
		return ;
	tmp = (*a);
	last = 0;
	while (tmp -> next)
	{
		if (!(tmp -> next -> next))
		{
			last = tmp -> next;
			tmp -> next = 0;
			break ;
		}
		tmp = tmp -> next;
	}
	if (last)
	{
		last -> next = (*a);
		(*a) = last;
	}
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	rev_rotate(a);
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	rev_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 3);
	rev_rotate(a);
	rev_rotate(b);
}
