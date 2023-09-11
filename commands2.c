/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:12:20 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/08 15:34:51 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int do_print)
{
	int	tmp;
	int	i;

	if (!a || a->size < 2)
		return ;
	tmp = a->array[0];
	i = 1;
	while (i < a->size)
	{
		a->array[i - 1] = a->array[i];
		i++;
	}
	a->array[i - 1] = tmp;
	if (do_print)
		put_command("ra");
}

void	rb(t_stack *b, int do_print)
{
	int	tmp;
	int	i;

	if (!b || b->size < 2)
		return ;
	tmp = b->array[0];
	i = 1;
	while (i < b->size)
	{
		b->array[i - 1] = b->array[i];
		i++;
	}
	b->array[i - 1] = tmp;
	if (do_print)
		put_command("rb");
}

void	rra(t_stack *a, int do_print)
{
	int	tmp;
	int	i;

	if (!a || a->size < 2)
		return ;
	tmp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	if (do_print)
		put_command("rra");
}

void	rrb(t_stack *b, int do_print)
{
	int	tmp;
	int	i;

	if (!b || b->size < 2)
		return ;
	tmp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
	if (do_print)
		put_command("rrb");
}

void	ss(t_stack *a, t_stack *b, int do_print)
{
	sa(a, 0);
	sb(b, 0);
	if (do_print)
		put_command("ss");
}
