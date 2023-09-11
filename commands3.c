/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:35:16 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/08 15:37:04 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b, int do_print)
{
	ra(a, 0);
	rb(b, 0);
	if (do_print)
		put_command("rr");
}

void	rrr(t_stack *a, t_stack *b, int do_print)
{
	rra(a, 0);
	rrb(b, 0);
	if (do_print)
		put_command("rrr");
}
