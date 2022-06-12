/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:10:16 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/12 14:45:41 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	kick(t_stack *a, t_stack *b, int x, int mean)
{
	int	count;

	count = 0;
	while (a->r[0] != x && a->end > 0)
	{
		if (a->at[0] == 1)
			count += rotate(a);
		else
			count += rev_rotate(a);
	}
	a->at[0] = 0;
	a->at[1] = 0;
	if (a->r[0] > mean)
		count += atob(a, b);
	else if (a->r[0] > mean && b->end > 1)
	{
		count += atob(a, b);
		count += rotate(b);
	}
	else
		count += atob(a, b);
	return (count);
}

int	kick2(t_stack *a, t_stack *b, int x)
{
	int	count;

	count = 0;
	while (a->r[0] != x)
	{
		if (a->at[0] == 1)
			count += rotate(a);
		else
			count += rev_rotate(a);
	}
	a->at[0] = 0;
	a->at[1] = 0;
	count += atob(a, b);
	return (count);
}

int	sort(t_stack *a, t_stack *b)
{
	int	x;
	int	count;

	count = 0;
	while (b->end - b->start > 0)
	{
		x = pcheck2(b);
		if (x == 0)
			x = ffmin(b);
		count += kick2(b, a, x);
	}
	return (count);
}

int	sortstack(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	marker(a);
	if (a->end == 5)
		count = sort5(a, b);
	else if (a->end < 500)
	{
		count += deck1(a, b);
		count += deck2(a, b);
		count += deck3(a, b);
		count += deck4(a, b);
		count += deck5(a, b);
		count += sort(a, b);
	}
	else
	{
		marker10(a);
		count += deck10(a, b);
		count += sort(a, b);
	}
	return (count);
}

int	sort5(t_stack *a, t_stack *b)
{
	int	count;
	int	i;
	int	x;

	i = 0;
	count = 0;
	x = 0;
	x = wherenum(a, a->max);
	count += kick2(a, b, x);
	x = wherenum(a, a->min);
	count += kick2(a, b, x);
	count += cases(a, b);
	return (count);
}
