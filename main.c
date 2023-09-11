/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:35:25 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/11 23:14:43 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	a.size_max = get_size_max(argv + 1, argc - 1);
	a.array = malloc(sizeof(int) * a.size_max);
	if (!a.array)
		put_error("Memory allocation failed.");
	a.size = 0;
	b.size_max = a.size_max;
	b.array = malloc(sizeof(int) * b.size_max);
	if (!b.array)
	{
		free(a.array);
		put_error("Memory allocation failed.");
	}
	b.size = 0;
	parse(argv + 1, &a, &b);
	if (!is_sorted(&a, &b))
		sort(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
