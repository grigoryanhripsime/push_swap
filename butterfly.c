/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:25:33 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/09 20:28:37 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_in_b(t_stack **a, t_stack **b)
{
	int	min;
	int	len;
	int	offset;

	min = 0;
	len = stack_len(*a);
	offset = my_log2(2 * len) * my_log5(0.25 * len);
	while (*a)
	{
		if ((*a)->index <= min)
		{
			pb(a, b);
			rb(b);
			min++;
		}
		else if ((*a)->index <= min + offset)
		{
			pb(a, b);
			min++;
		}
		else
			ra(a);
	}
}

int	get_position(t_stack *a, int index)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a -> index == index)
			return (i);
		i++;
		a = a -> next;
	}
	return (i);
}

void	sort_in_a(t_stack **a, t_stack **b)
{
	int	max;
	int	position;

	max = stack_len(*b) - 1;
	while (*b)
	{
		position = get_position(*b, max);
		if (position <= stack_len(*b) / 2)
		{
			while (position-- > 0)
				rb(b);
		}
		else
		{
			while (position++ < stack_len(*b) - 1)
				rrb(b);
			rrb(b);
		}
		pa(a, b);
		max--;
	}
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	sort_in_b(a, b);
	sort_in_a(a, b);
}
