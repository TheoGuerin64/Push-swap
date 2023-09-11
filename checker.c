/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:13:37 by tguerin           #+#    #+#             */
/*   Updated: 2023/03/16 19:32:05 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execut_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		rra(a, 0);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		rrb(b, 0);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static int	check(t_stack *a, t_stack *b)
{
	char	*s;
	int		return_value;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (!execut_cmd(a, b, s))
		{
			free(s);
			free_stacks(a, b);
			put_error("Command doesn't exist.");
		}
		free(s);
	}
	return_value = is_sorted(a, b);
	return (return_value);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
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
	if (check(&a, &b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&a, &b);
	return (0);
}
