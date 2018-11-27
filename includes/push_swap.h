/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 05:01:17 by vnxele            #+#    #+#             */
/*   Updated: 2018/10/09 12:10:39 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_stack
{
	int		data;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

typedef struct		s_vars
{
	t_stack		*a;
	t_stack		*b;
	char		*line;
	int		flag;
	int		low;
	int		high;
	int		i;
	int		j;
	int		maxh;
	int		maxl;
}			t_vars;

void			push(t_stack **head_ref, int new_data);
void			append(t_stack **head_ref, int new_data);
int			swap_a(t_stack **a, int p);
int			swap_b(t_stack **b, int p);
int			ss(t_stack **a, t_stack **b, int p);
int			push_a(t_stack **a, t_stack **b, int p);
int			push_b(t_stack **a, t_stack **b, int p);
int			rotate_a(t_stack **a, int p);
int			rotate_b(t_stack **b, int p);
int			rr(t_stack **a, t_stack **b, int p);
int			reverse_ra(t_stack **a, int p);
int			reverse_rb(t_stack **b, int p);
int			rrr(t_stack **a, t_stack **b, int p);
int			execute_operation(char *line, t_stack **a, t_stack **b, int p);
int			check_order(t_stack *a);
int			data_count(t_stack *head);
int			valid_av(char **av);
void			simple_solve(t_stack **a, t_stack **b, t_vars *var);
void			solve4(t_stack **a, t_stack **b, t_vars *var);
void			hlf(t_stack *a, int *arr, int dc);
int			hlf_cmp(t_stack *a, int c, int *arr);
void			solve(t_stack **a, t_stack **b, t_vars var, int dc);
t_stack			*smllr(t_stack *a);
int			get_distance(t_stack *a, int c);
int			get_lst(t_stack *a);
int			hvyside(t_stack *a);
int			get_hlf(t_stack *a);
int			anlyz(t_stack *a, int arr[]);
void			bsolve(t_stack **a, t_stack **b, int arr[]);

# endif
