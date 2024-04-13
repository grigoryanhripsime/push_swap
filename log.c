/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:30:41 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 13:31:06 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_log2(int x)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	while (i < x)
	{
		count++;
		i *= 2;
	}
	return (count + 1);
}

int	my_log5(int x)
{
	int	i;
	int	count;

	i = 5;
	count = 0;
	while (i < x)
	{
		count++;
		i *= 5;
	}
	return (count + 1);
}
