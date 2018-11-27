/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 06:31:29 by vnxele            #+#    #+#             */
/*   Updated: 2018/10/17 16:37:21 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		data_count(t_stack *head)
{
	int	r;

	r  = 0;
	while (head)
	{
		r++;
		head = head->next;
	}
	return (r);
}

t_stack		*smllr(t_stack *a)
{
	int	i;

	i = a->data;
	while (a)
	{
		if (a->data < i)
			return (a);
		a = a->next;
	}

	return (NULL);
}

int		get_lst(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->data);
}

void	simple_solve(t_stack **a, t_stack **b, t_vars *var)
{
	t_stack  *tmp;

	tmp = *a;
	var->low = tmp->data;
	var->high = tmp->data;
	while (tmp)
	{
		if (tmp->data > var->high)
			var->high = tmp->data;
		if (tmp->data < var->low)
			var->low = tmp->data;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->data != var->low && tmp->data != var->high)
			break ;
		if (!tmp->prev)
			break ;
		tmp = tmp->prev;
	}
	if (tmp->prev == NULL)
		if (tmp->data > tmp->next->data)
			execute_operation("sa", a, b, 1);
		else
			execute_operation("rra", a, b, 1);
	else if (tmp->next == NULL && tmp->data > tmp->prev->data)
		execute_operation("ra", a, b, 1);
	else if (tmp->prev->data > tmp->data)
		execute_operation("sa", a, b, 1);
	else
		execute_operation("rra", a, b, 1);
}

int	push_swap(char **av)
{
	t_vars var;
	t_stack *tmp;

	var.i = 1;
	var.a = NULL;
	var.b = NULL;
	while (av[var.i])
		append(&var.a, ft_atoi(av[var.i++]));
	var.low = var.a->data;
	var.high = var.a->data;
	tmp = var.a;
	while (tmp)
	{
		if (tmp->data < var.low)
			var.low = tmp->data;
		if (tmp->data > var.high)
			var.high = tmp->data;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	while (42)
	{
		if (!check_order(var.a) && !var.b)
			break ;
		if (data_count(var.a) < 4)
			simple_solve(&var.a, &var.b, &var);
		if (data_count(var.a) == 4 || var.b)
			solve4(&var.a, &var.b, &var);
		if (data_count(var.a) > 4)
			solve(&var.a, &var.b, var, data_count(var.a));
	}
	write(1, "\n", 1);
	while (var.a || var.b)
	{
		if (var.a)
			ft_putnbr(var.a->data);
		else
			write(1, " ",1);
		if (var.b)
		{
			write(1, " ", 1);
			ft_putnbr(var.b->data);
			var.b = var.b->next;
		}
		write(1, "\n", 1);
		if (var.a)
			var.a = var.a->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (valid_av(av))
		return (push_swap(av));
	else
	{
		ft_putendl("Error");
		return (1);
	}
	return (0);
}
