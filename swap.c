/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:38:47 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 13:39:13 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a) || stack_len(*a) < 2)
		return ;
	tmp = (*a);
	(*a) = (*a)-> next;
	tmp -> next = (*a)-> next;
	(*a)-> next = tmp;
}

void	sa(t_stack **a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack **b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
