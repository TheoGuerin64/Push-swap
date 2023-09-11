/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 05:21:56 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/11 23:01:40 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_max(char **str, int size)
{
	int	size_max;
	int	i;
	int	j;

	size_max = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		size_max += 1;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				size_max += 1;
			j++;
		}
		i++;
	}
	return (size_max);
}

int	is_duplicates(t_stack *a)
{
	int	i;
	int	j;

	if (!a)
		return (0);
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->array[i] == a->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	parse_split(char **split, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!is_digits(split[i]))
		{
			free_split(split);
			free(a->array);
			free(b->array);
			put_error("Some arguments aren't integers.");
		}
		if (!is_int(split[i]))
		{
			free_split(split);
			free(b->array);
			free(a->array);
			put_error("Some arguments are bigger than an integer.");
		}
		a->array[a->size] = ft_atoi(split[i]);
		a->size++;
		i++;
	}
}

void	parse(char **strings, t_stack *a, t_stack *b)
{
	char	**tmp;
	int		i;

	i = 0;
	while (strings[i])
	{
		tmp = ft_split(strings[i], ' ');
		if (!tmp || !tmp[0])
			free(tmp);
		parse_split(tmp, a, b);
		free_split(tmp);
		i++;
	}
	if (is_duplicates(a))
	{
		free_stacks(a, b);
		put_error("There are duplicates.");
	}
}
