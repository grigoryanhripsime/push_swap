/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:56:19 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/03 14:57:22 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	list_len(t_list *lst)
{
	int	len;
	int	i;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst -> content[i])
		{
			len++;
			if (lst -> content[i] == '\n')
				return (len);
			i++;
		}
		lst = lst -> next;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		s1_size;
	char	*s2;
	int		i;

	i = 0;
	s1_size = ft_strlen_gnl(s1);
	s2 = (char *)malloc(s1_size * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	look_for_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

int	there_is_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
