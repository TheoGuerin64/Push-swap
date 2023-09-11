/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:39:58 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/08 15:28:49 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_command(char *command_name)
{
	write(1, command_name, ft_strlen(command_name));
	write(1, "\n", 1);
}

void	sa(t_stack *a, int do_print)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = tmp;
	if (do_print)
		put_command("sa");
}

void	sb(t_stack *b, int do_print)
{
	int	tmp;

	if (!b || b->size < 2)
		return ;
	tmp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = tmp;
	if (do_print)
		put_command("sb");
}

void	pa(t_stack *a, t_stack *b, int do_print)
{
	int	i;

	if (!a || !b || b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = b->array[0];
	i = 1;
	while (i < b->size)
	{
		b->array[i - 1] = b->array[i];
		i++;
	}
	a->size++;
	b->size--;
	if (do_print)
		put_command("pa");
}

void	pb(t_stack *a, t_stack *b, int do_print)
{
	int	i;

	if (!a || !b || a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = a->array[0];
	i = 1;
	while (i < a->size)
	{
		a->array[i - 1] = a->array[i];
		i++;
	}
	a->size--;
	b->size++;
	if (do_print)
		put_command("pb");
}
