/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 21:25:49 by vnxele            #+#    #+#             */
/*   Updated: 2018/09/22 08:45:00 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap_a(t_stack **a, int p)
{
	t_stack *tmp_node;

	tmp_node = (t_stack*)malloc(sizeof(t_stack));
	if (!*a || !(*a)->next)
		return (0);
	tmp_node->data = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp_node->data;
	if (p)
		ft_putendl("sa");
	return (0);
}

int	swap_b(t_stack **b, int p)
{
	t_stack *tmp_node;

	tmp_node = (t_stack*)malloc(sizeof(t_stack));
	if (!*b || !(*b)->next)
		return (0);
	tmp_node->data = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp_node->data;
	if (p)
		ft_putendl("sb");
	return (0);
}

int	ss(t_stack **a, t_stack **b, int p)
{
	swap_a(a, 0);
	swap_b(b, 0);
	if (p)
		ft_putendl("ss");
	return (0);
}

int	push_a(t_stack **a, t_stack **b, int p)
{
	if (!*b)
		return (0);
	push(a, (*b)->data);
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	if (p)
		ft_putendl("pa");
	return (0);
}

int	push_b(t_stack **a, t_stack **b, int p)
{
	if (!*a)
		return (0);
	push(b, (*a)->data);
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (p)
		ft_putendl("pb");
	return (0);
}
