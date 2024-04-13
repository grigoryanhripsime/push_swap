/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:23:35 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 18:47:50 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_list(char **nums, int nums_count)
{
	int	i;

	i = 0;
	while (i < nums_count)
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
}

void	error_exit_with_free(char **nums, int nums_count, t_stack **a)
{
	free_list(nums, nums_count);
	free_stack(a);
	error_exit();
}
