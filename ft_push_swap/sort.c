/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:07:11 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 16:39:48 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deck1(t_stack *a, t_stack *b)
{
	int	v;
	int	x;
	int	count;
	int	means;

	count = 0;
	v = a->mark[1];
	means = mean(a, 1);
	while (eval(a, v) != 0 && a->end > 0)
	{
		x = pcheck(a, v);
		if (x == 0)
			x = ffmin(a);
		count += kick(a, b, x, means);
	}
	return (count);
}

int	deck2(t_stack *a, t_stack *b)
{
	int	v;
	int	x;
	int	count;
	int	means;

	means = mean(a, 2);
	count = 0;
	v = a->mark[2];
	while (eval(a, v) != 0 && a->end > 0)
	{
		x = pcheck(a, v);
		if (x == 0)
			x = ffmin(a);
		count += kick(a, b, x, means);
	}
	return (count);
}

int	deck3(t_stack *a, t_stack *b)
{
	int	v;
	int	x;
	int	count;
	int	means;

	means = mean(a, 3);
	count = 0;
	v = a->mark[3];
	while (eval(a, v) != 0 && a->end > 0)
	{
		x = pcheck(a, v);
		if (x == 0)
			x = ffmin(a);
		count += kick(a, b, x, means);
	}
	return (count);
}

int	deck4(t_stack *a, t_stack *b)
{
	int	v;
	int	x;
	int	count;
	int	means;

	means = mean(a, 4);
	count = 0;
	v = a->mark[4];
	while (eval(a, v) != 0 && a->end > 0)
	{
		x = pcheck(a, v);
		if (x == 0)
			x = ffmin(a);
		count += kick(a, b, x, means);
	}
	return (count);
}

int	deck5(t_stack *a, t_stack *b)
{
	int	count;
	int	means;

	means = mean(a, 5);
	count = 0;
	while (a->end >= 1 && a->end > 0)
	{
		if (a->r[0] > means)
			count += atob(a, b);
		else
		{
			count += atob(a, b);
			count += rotate(b);
		}
	}
	b->max = ffmax(b);
	b->min = ffmin(b);
	return (count);
}
