/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:23:41 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 18:53:18 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	validation(argv);
	a = NULL;
	init_stack(argv, &a);
	b = NULL;
	setting_indexes(&a);
	if (!sorted(a))
	{
		if (stack_len(a) <= 6)
			simple_sort(&a, &b);
		else
			butterfly_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
