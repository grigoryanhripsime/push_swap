/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:19:25 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/09 20:23:26 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	print_stacks(t_stack *a, t_stack *b);
char	**ft_split(char const *s);
int		ft_strlen(char *s);
int		ft_isspace(char c);
int		ft_words_count(char *s);
int		sorted(t_stack *a);
void	error_exit(void);
void	free_list(char **nums, int nums_count);
void	error_exit_with_free(char **nums, int nums_count, t_stack **a);
void	validation(char **args);
int		check_for_valid_num(t_stack *a, char *str);
void	init_stack(char **args, t_stack **a);
void	swap(t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	setting_indexes(t_stack **a);
int		stack_len(t_stack *a);
void	simple_sort(t_stack **a, t_stack **b);
void	butterfly_sort(t_stack **a, t_stack **b);
int		my_log2(int x);
int		my_log5(int x);
void	free_stack(t_stack **a);
int		push_bonus(t_stack **a, t_stack **b, char *str);
int		swap_bonus(t_stack **a, t_stack **b, char *str);
int		rotate_bonus(t_stack **a, t_stack **b, char *str);
int		rev_rotate_bonus(t_stack **a, t_stack **b, char *str);
int		ft_strcmp(const char *s1, const char *s2);

#endif