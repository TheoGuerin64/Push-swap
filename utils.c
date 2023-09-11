/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:21:05 by tguerin           #+#    #+#             */
/*   Updated: 2022/11/08 02:07:23 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *error_msg)
{
	write(2, "Error\n", 6);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(1);
}

int	is_digits(char *s)
{
	if ((s[0] == '-' || s[0] == '+') && s[1])
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	is_bigger(char *max, char *s)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (s[i] > max[i])
			return (0);
		if (s[i] < max[i])
			return (1);
		i++;
	}
	return (1);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->array);
	free(b->array);
}

int	is_int(char *s)
{
	int	is_neg;
	int	tmp;

	is_neg = 0;
	if (*s == '-')
		is_neg = 1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s == '0')
		s++;
	if (ft_strlen(s) > 10)
		return (0);
	else if (ft_strlen(s) < 10)
		return (1);
	else
	{
		if (is_neg)
			tmp = is_bigger("2147483648", s);
		else
			tmp = is_bigger("2147483647", s);
		return (tmp);
	}
}
