/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:20:45 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/08 15:32:54 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			if (i > 0)
				i -= 1;
		}
		else
			i++;
	}
}

int	*get_sorted_array(t_stack *stack)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		array[i] = stack->array[i];
		i++;
	}
	sort_array(array, stack->size);
	return (array);
}

static int	index_distance(int size, int index)
{
	if (index > size / 2)
		return (size - index + 1);
	else
		return (index);
}

static int	get_index(t_stack *b, t_exec_state *exec_state)
{
	int	index;
	int	tmp;

	index = max_index(b, -1);
	tmp = max_index(b, index);
	if (*exec_state == MINUS_ONE)
		*exec_state = MAX_AFTER_MINUS_ONE;
	else if (index_distance(b->size, index) > index_distance(b->size, tmp))
	{
		index = tmp;
		*exec_state = MINUS_ONE;
	}
	return (index);
}

void	insert_sort(t_stack *a, t_stack *b)
{
	void			(*command)(t_stack *, int);
	t_exec_state	exec_state;
	int				index;
	int				tmp;

	exec_state = NORMAL;
	while (b->size)
	{
		index = get_index(b, &exec_state);
		command = &rb;
		if (index > b->size / 2)
			command = &rrb;
		tmp = b->array[index];
		while (b->array[0] != tmp)
			command(b, 1);
		pa(a, b, 1);
		if (exec_state == MAX_AFTER_MINUS_ONE)
		{
			sa(a, 1);
			exec_state = NORMAL;
		}
	}
}
