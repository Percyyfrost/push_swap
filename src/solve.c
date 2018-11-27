/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:56:21 by vnxele            #+#    #+#             */
/*   Updated: 2018/10/17 15:02:08 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_distance(t_stack *a, int c)
{
        int	r;
        t_stack	*tmp;

	tmp = a;
	r = 0;
	while (c < tmp->data)
	{
		r++;
		tmp = tmp->next;
	}
	if (!tmp)
		return (0);
	return (r);
}

void		solve4(t_stack **a, t_stack **b, t_vars *var)
{
	if (var->high == (*a)->data && !*b)
		execute_operation("ra", a, b, 1);
	if ((*a)->data > (*a)->next->data && !*b)
		execute_operation("sa", a, b, 1);
	t_stack *tmp = *a;
	while (tmp->next)
	{
		if(tmp->data > tmp->next->data)
			break ;
		tmp = tmp->next;
	}
	if (*b && !tmp->next)
		execute_operation("pa", a, b, 1);
	if (tmp->next && !*b)
		execute_operation("pb", a, b, 1);
}

void		fsolve(t_stack *tmp, t_stack *num, t_stack **a, t_stack **b)
{
	int	s;

	s = 0;
	while (tmp)
	{
		if ((num = smllr(tmp)))
			s = get_distance(tmp, num->data);
		if (*a && (*a)->next && !s && (*a)->data < (*a)->next->data && check_order(*a))
			execute_operation("pb", a, b, 1);
		while (num && s)
		{
			if (*b && (*b)->next)
			{
				if (*a && (*a)->next && (*a)->data > (*a)->next->data && (*b)->data < (*b)->next->data)
					execute_operation("ss", a, b, 1);
				else if ((*b)->data < (*b)->next->data)
					execute_operation("sb", a, b, 1);
			}

			if (*a && (*a)->next && (*a)->data > (*a)->next->data)
				execute_operation("sa", a, b, 1);
			else if (check_order(*a))
				execute_operation("pb", a, b, 1);
			s--;
		}
		tmp = tmp->next;
	}
}

void		solve(t_stack **a, t_stack **b, t_vars var, int dc)
{
        t_stack	*tmp;
        t_stack	*num;
        int	s;
        int	lst;
	int	h;
        int	arr[dc];

	s = 0;
	num = NULL;
	h = get_hlf(var.a);
	hlf(var.a, arr, dc);
	//fix this man yoh
	while (hlf_cmp(*a, (*a)->data, arr) && data_count(*a) > 3 && (*a)->data != h)
                        execute_operation("ra", a, b, 1);
	if (!hvyside(*a))
			bsolve(a, b, arr);
	while (42)
	{
		tmp = var.a;
		lst = get_lst(var.a);
		if (!check_order(*a) && !*b)
			break ;
//		while (hlf_cmp(*a, (*a)->data, arr) && data_count(*a) > 3 && (*a)->data != h)
//			execute_operation("ra", a, b, 1);
		if (data_count(var.a) == 4 || var.b)
			solve4(&var.a, &var.b, &var);
		for (int i = 1000; i; i--)
		{
			if (!hlf_cmp(*a, get_lst(*a), arr))
			{
				execute_operation("rra", a, b, 1);
				if ((*a)->data > (*a)->next->data)
					execute_operation("sa", a, b, 1);
				if ((*a)->data < (*a)->next->data)
					execute_operation("pb", a, b, 1);
			}
			else
				break ;
		}
		if (*a && (*a)->next && (*a)->data > (*a)->next->data)
			execute_operation("sa", a, b, 1);
		fsolve(tmp, num, a, b);
		while (*b && !check_order(*a))
		{
			execute_operation("pa", a, b, 1);
			if ((*a)->data > (*a)->next->data)
				execute_operation("sa", a, b, 1);
		}
	}
}
