/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:29:06 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 16:55:01 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	push_bonus(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(b, a);
	else
		return (0);
	return (1);
}

int	swap_bonus(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(str, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else
		return (0);
	return (1);
}

int	rotate_bonus(t_stack **a, t_stack **b, char *str)
{
	if (ft_strlen(str) != 3)
		return (0);
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else
		return (0);
	return (1);
}

int	rev_rotate_bonus(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp(str, "rra\n") == 0)
		rev_rotate(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rev_rotate(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		return (0);
	return (1);
}
