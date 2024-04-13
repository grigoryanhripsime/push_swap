/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:39:30 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 18:44:45 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	validation(char **args)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (args[i])
	{
		j = 0;
		flag = 0;
		if (!*args[i])
			error_exit();
		while (args[i][j])
		{
			if (ft_isspace(args[i][j]))
				flag++;
			if ((args[i][j] < '0' || args[i][j] > '9') && args[i][j] != '-'
				&& args[i][j] != '+' && !ft_isspace(args[i][j]))
				error_exit();
			j++;
		}
		if (flag == j)
			error_exit();
		i++;
	}
}

static int	is_in_stack(t_stack *a, int num)
{
	while (a)
	{
		if (a -> data == num)
			return (1);
		a = a -> next;
	}
	return (0);
}

void	check_for_valid_char(char *str, int *i, int *sign)
{
	if (str[*i] == '-' && str[*i + 1]
		&& str[*i + 1] >= '0' && str[*i + 1] <= '9')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+' && str[*i + 1]
		&& str[*i + 1] >= '0' && str[*i + 1] <= '9')
		(*i)++;
	while (str[*i] == '0' && str[*i + 1])
		(*i)++;
}

int	check_for_valid_num(t_stack *a, char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	check_for_valid_char(str, &i, &sign);
	if (ft_strlen(str + i) > 10)
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + str[i++] - '0';
	if (str[i] || sign * num > INT_MAX || sign * num < INT_MIN)
		return (0);
	if (is_in_stack(a, sign * num))
		return (0);
	return (1);
}
