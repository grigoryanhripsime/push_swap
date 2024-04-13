/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:34:26 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 15:24:53 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *a)
{
	int	min;

	if (!a)
		return (0);
	min = a -> data;
	a = a -> next;
	while (a)
	{
		if (a -> data <= min)
			return (0);
		min = a -> data;
		a = a -> next;
	}
	return (1);
}

void	sort_a3(t_stack **a, int len_b)
{
	if ((*a)-> index == len_b + 2)
	{
		ra(a);
		if ((*a)-> index > (*a)-> next -> index)
			sa(a);
	}
	else if ((*a)-> index == len_b
		&& (*a)-> next -> index > (*a)-> next -> next -> index)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)-> index == len_b + 1)
	{
		if ((*a)-> next -> index > (*a)-> next -> next -> index)
			rra(a);
		else
			sa(a);
	}
}

void	sort_b3(t_stack **b)
{
	if ((*b)-> index == 1)
	{
		if ((*b)-> next -> index > (*b)-> next -> next -> index)
			sb(b);
		else
			rrb(b);
	}
	else if ((*b)-> index == 2
		&& (*b)-> next -> index < (*b)-> next -> next -> index)
	{
		rrb(b);
		if ((*b)-> index < (*b)-> next -> index)
			sb(b);
	}
	else if ((*b)-> index == 0)
	{
		rb(b);
		if ((*b)-> index < (*b)-> next -> index)
			sb(b);
	}
}

int	min_in_a(t_stack *a, int len)
{
	while (a)
	{
		if (a -> index < len - 3)
			return (1);
		a = a -> next;
	}
	return (0);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	while (stack_len(*a) > 3 || min_in_a(*a, len))
	{
		if ((*a)-> index >= len / 2)
			ra(a);
		else
			pb(a, b);
	}
	if (stack_len(*a) == 2 && (*a)-> index > (*a)-> next -> index)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_a3(a, stack_len(*b));
	if (stack_len(*b) == 2 && (*b)-> index < (*b)-> next -> index)
		sb(b);
	else if (stack_len(*b) == 3)
		sort_b3(b);
	while ((*b))
		pa(a, b);
}
