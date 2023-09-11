/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:51:39 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/09 19:29:41 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size > 0)
		return (0);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->array[i] > a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	index_of(int *list, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (list[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
