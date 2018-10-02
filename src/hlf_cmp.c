/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hlf_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 06:09:15 by vnxele            #+#    #+#             */
/*   Updated: 2018/09/20 16:02:44 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int		partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = (low - 1);
	pivot = arr[high];
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void		qicsort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		qicsort(arr, low, pi - 1);
		qicsort(arr, pi + 1, high);
	}
}

void		hlf(t_stack *a, int *arr, int dc)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	qicsort(arr, 0, dc + 1 / 2);
}

int		hlf_cmp(t_stack *a, int c, int *arr)
{
	int	i;
	int	len;

	len = data_count(a);
	i = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			break ;
		i++;
	}
	if (i > len/2)
		return (1);
	return (0);
}
