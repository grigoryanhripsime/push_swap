/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:24:40 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 13:24:56 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_words_count(char *s)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (i <= (int)ft_strlen(s))
	{
		if ((ft_isspace(s[i]) || s[i] == '\0') && flag)
		{
			count++;
			flag = 0;
		}
		else if (!ft_isspace(s[i]))
			flag = 1;
		i++;
	}
	return (count);
}

static char	*init(int len, char *s)
{
	char	*element;
	int		i;

	i = 0;
	element = malloc((len + 1) * sizeof(char));
	if (!element)
		return (0);
	while (i < len)
	{
		element[i] = s[i];
		i++;
	}
	element[len] = '\0';
	return (element);
}

static int	fill(char **arr, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		if ((ft_isspace(s[len]) || s[len] == '\0') && len)
		{
			arr[i] = init(len, s);
			if (!arr[i])
				return (0);
			s += len;
			len = 0;
			i++;
		}
		else if (!ft_isspace(s[len]) && s[len] != '\0')
			len++;
		else
			s++;
	}
	return (1);
}

char	**ft_split(char const *s)
{
	int		w_count;
	char	**arr;

	if (!s)
		w_count = 0;
	else
		w_count = ft_words_count((char *) s);
	arr = malloc((w_count + 1) * sizeof(char *));
	if (!arr)
		return (0);
	arr[w_count] = 0;
	if (!w_count)
		return (arr);
	if (!fill(arr, (char *) s))
		return (0);
	return (arr);
}
