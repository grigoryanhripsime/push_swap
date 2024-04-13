/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:28:23 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 18:45:41 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] == '0' && str[i + 1])
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (sign * num);
}

static t_stack	*ft_lst_last(t_stack *a)
{
	while (a -> next)
		a = a -> next;
	return (a);
}

static t_stack	*ft_lst_new(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		error_exit();
	node -> data = num;
	node -> next = NULL;
	return (node);
}

static void	add_to_stack(char *n, t_stack **a)
{
	int	num;

	num = ft_atoi(n);
	if (!(*a))
		*a = ft_lst_new(num);
	else
		ft_lst_last(*a)-> next = ft_lst_new(num);
}

void	init_stack(char **args, t_stack **a)
{
	int		i;
	char	**nums;
	int		nums_count;
	int		j;

	i = 1;
	while (args[i])
	{
		nums_count = ft_words_count(args[i]);
		nums = ft_split(args[i]);
		j = 0;
		while (nums[j])
		{
			if (!check_for_valid_num(*a, nums[j]))
				error_exit_with_free(nums, nums_count, a);
			add_to_stack(nums[j], a);
			j++;
		}
		i++;
		free_list(nums, nums_count);
	}
}
