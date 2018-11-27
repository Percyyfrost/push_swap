/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 05:58:26 by vnxele            #+#    #+#             */
/*   Updated: 2018/10/17 16:36:43 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		hvyside(t_stack *a)
{
	int	i;
	int 	x;
	int 	b;
	int	c;

	x = 0;
	b = 0;
	i = 0;
	c = data_count(a)/2;
	while (a && i < c)
	{
		x += a->data;
		a = a->next;
		i++;
	}
	while (a)
	{
		b += a->data;
		a = a->next;
	}
	if (b > x)
		return (1);
	else
		return (0);
}

int		get_hlf(t_stack *a)
{
	int	i;
	int 	h;

	i = 0;
	h = 0;
	while (a && i < data_count(a))
	{
		h = a->data;
		a = a->next;
		i++;
	}
	return (h);
}

int		anlyz(t_stack *a, int arr[])
{
	int	i;
	int 	x;
	int 	y;
	int	hlf;

	i = 0;
	x = 0;
	y = 0;
	hlf = get_hlf(a);
	while (a)
	{
		if (a->data != arr[i] && i < hlf)
			x++;
		if (a->data != arr[i] && i > hlf)
			y++;
		a = a->next;
		i++;
	}
	if (x > y)
		return (0);
	return (1);
}

void		bsolve(t_stack **a, t_stack **b, int arr[])
{
	int	lst;
	int	hlf;
	int	i;
	t_stack	*tmp;

	lst = get_lst(*a);
	tmp = *a;
	hlf = get_hlf(*a);
	i = 0;
	arr = 0;
	while (lst != hlf)
	{
		lst = get_lst(*a);
		//if ((*a)->next && hlf_cmp(*a, lst, arr))
//	while (hlf_cmp(*a, lst, arr))
//	{
		execute_operation("rra", a, b, 1);
//		if (lst == get_lst(*a))
//			break ;
//		lst = get_lst(*a);
//	}
		if (*b && (*b)->next)
		{
			if ((*a)->data > (*a)->next->data && (*b)->data < (*b)->next->data)
				execute_operation("ss", a, b, 1);
			if ((*b)->next->next && (*b)->data < (*b)->next->data && (*b)->data < (*b)->next->next->data)
				execute_operation("rb", a, b, 1);
			if ((*b)->data < (*b)->next->data)
				execute_operation("sb", a, b, 1);
		}
		if ((*a)->data > (*a)->next->data)
			execute_operation("sa", a, b, 1);
		if (i && (*a)->data < (*a)->next->data)
			execute_operation("pb", a, b, 1);
		else if ((*b) && !check_order(*a))
			execute_operation("pa", a, b, 1);
		i++;
	}
	//make nice if statement
//	if (*a && *b && hlf_cmp(*a, (*a)->data, arr) && data_count(*a) > 3
//		&& !hlf_cmp(*b, (*b)->data, arr))
//		execute_operation("rr", a, b, 1);
}
