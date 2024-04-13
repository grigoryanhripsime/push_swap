/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:21:34 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/10 16:31:36 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_to_list(t_list **lst, char *str)
{
	t_list	*node;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new -> content = str;
	new -> next = NULL;
	node = *lst;
	if (!node)
	{
		*lst = new;
		return ;
	}
	while (node -> next)
		node = node -> next;
	node -> next = new;
}

void	create_list(t_list **lst, int fd)
{
	char	*str;
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return ;
	while (bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(str);
			return ;
		}
		str[bytes_read] = '\0';
		add_to_list(lst, ft_strdup(str));
		if (there_is_nl(str))
			break ;
	}
	free(str);
	return ;
}

char	*create_line(t_list *lst, int line_len)
{
	char	*str;
	int		i;
	int		j;

	if (!lst || !line_len)
		return (0);
	i = 0;
	str = malloc((line_len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < line_len && lst)
	{
		j = 0;
		while (i < line_len && lst -> content[j])
		{
			str[i] = lst -> content[j];
			i++;
			j++;
		}
		lst = lst -> next;
	}
	str[i] = '\0';
	return (str);
}

void	clear_list(t_list **lst)
{
	t_list	*tmp;
	int		before_nl;
	char	*str;

	while (*lst)
	{
		before_nl = look_for_newline((*lst)->content);
		if (there_is_nl((*lst)->content))
		{
			str = ft_strdup((*lst)->content + before_nl);
			free((*lst)->content);
			(*lst)->content = str;
			return ;
		}
		else
		{
			tmp = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*next_line;
	int				line_len;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, next_line, 0) < 0)
		return (NULL);
	create_list(&lst, fd);
	line_len = list_len(lst);
	next_line = create_line(lst, line_len);
	clear_list(&lst);
	return (next_line);
}
