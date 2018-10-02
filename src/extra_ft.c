/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvvar.in@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 06:48:03 by vnxele            #+#    #+#             */
/*   Updated: 2018/09/23 12:57:16 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		valid_av(char **av)
{
	t_vars	var;

	var.maxh = 2147483647;
	var.maxl = -2147483648;
	var.i = 1;
	while (av[var.i])
	{
		var.j = 0;
		while (av[var.i][var.j])
			if (!ft_isdigit(av[var.i][var.j++]) && av[var.i][0] != '-')
				return (0);
			if (ft_atoi(av[var.i]) < var.maxl && ft_atoi(av[var.i]) > var.maxh)
				return (0);
		var.i++;
	}
	var.i = 1;
	while (av[var.i])
	{
		var.j = 0;
		while (av[var.j])
		{
			if (!ft_strcmp(av[var.i], av[var.j]) && var.i != var.j)
				return (0);
			var.j++;
		}
		var.i++;
	}
	return (1);
}

void		push(t_stack **head, int new_data)
{
	t_stack	*new_node;

	new_node = (t_stack*)malloc(sizeof(t_stack));
	new_node->data = new_data;
	new_node->next = (*head);
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
}

void		append(t_stack **head, int new_data)
{
	t_stack	*new_node;
	t_stack	*last;

	last = *head;
	new_node = (t_stack*)malloc(sizeof(t_stack));
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return ;
}

int		rrr(t_stack **a, t_stack **b, int p)
{
	reverse_ra(a, 0);
	reverse_rb(b, 0);
	if (p)
		ft_putendl("rrr");
	return (0);
}
