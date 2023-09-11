/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:33:11 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/10 18:02:53 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a, int *sorted)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = index_of(sorted, 3, a->array[0]) + 1;
	i2 = index_of(sorted, 3, a->array[1]) + 1;
	i3 = index_of(sorted, 3, a->array[2]) + 1;
	if (i1 == 1 && i2 == 3 && i3 == 2)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (i1 == 2 && i2 == 3 && i3 == 1)
		rra(a, 1);
	else if (i1 == 2 && i2 == 1 && i3 == 3)
		sa(a, 1);
	else if (i1 == 3 && i2 == 1 && i3 == 2)
		ra(a, 1);
	else if (i1 == 3 && i2 == 2 && i3 == 1)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

static void	go_to_max(t_stack *a)
{
	void	(*command)(t_stack *, int);
	int		index_max;
	int		max;
	int		i;

	index_max = 0;
	max = a->array[0];
	i = 0;
	while (i < a->size)
	{
		if (a->array[i] > max)
		{
			index_max = i;
			max = a->array[i];
		}
		i++;
	}
	command = &ra;
	if (index_max > a->size / 2)
		command = &rra;
	while (a->array[0] != max)
		command(a, 1);
}

static void	smart_insert_sort(t_stack *a, t_stack *b, int *sorted)
{
	while (a->size > 3)
	{
		go_to_max(a);
		pb(a, b, 1);
	}
	sort_three(a, sorted);
	while (b->size)
	{
		pa(a, b, 1);
		ra(a, 1);
	}
}

int	sort_small(t_stack *a, t_stack *b)
{
	int	*sorted;

	sorted = get_sorted_array(a);
	if (!sorted)
		return (0);
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a, 1);
	}
	else
		smart_insert_sort(a, b, sorted);
	free(sorted);
	return (1);
}
