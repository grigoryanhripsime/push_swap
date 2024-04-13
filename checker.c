/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:31:22 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 18:51:13 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	valid_instruct(char *str, t_stack **a, t_stack **b)
{
	if (ft_strlen(str) < 2)
		return (0);
	if (str[0] == 'p' && push_bonus(a, b, str))
		return (1);
	else if (str[0] == 's' && swap_bonus(a, b, str))
		return (1);
	else if (str[0] == 'r' && (rotate_bonus(a, b, str)
			|| rev_rotate_bonus(a, b, str)))
		return (1);
	else
		return (0);
}

void	get_instructs(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (valid_instruct(str, a, b) == 0)
		{
			if (!ft_strlen(str))
				break ;
			free_stack(a);
			error_exit();
		}
		free(str);
	}
}

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
	get_instructs(&a, &b);
	if (!sorted(a) || stack_len(b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&a);
	return (0);
}
