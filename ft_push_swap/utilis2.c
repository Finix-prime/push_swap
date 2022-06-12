/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:00:14 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/12 13:51:54 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*setstack(t_stack *a, char n)
{
	int	i;

	i = 0;
	a->start = 0;
	a->end = 0;
	a->max = 0;
	a->min = 0;
	a->at[0] = 0;
	a->at[1] = 0;
	a->name = n;
	a->check = 0;
	while (i < 20)
	{
		a->mark[i] = 0;
		i++;
	}
	return (a);
}

int	mean(t_stack *stk, int i)
{
	int	j;
	int	ans;
	int	n;

	j = 0;
	n = 0;
	ans = 0;
	while (j < stk->end)
	{
		if (stk->r[j] <= stk->mark[i - 1] && stk->r[j] > stk->mark[i])
		{
			stk->c[n] = stk->r[j];
			ans += stk->c[n];
			n++;
		}
		j++;
	}
	if (n == 0)
		return (ffmin(stk));
	return (ans / n);
}

int	ffmax(t_stack *stk)
{
	int	i;
	int	n;
	int	c;

	i = stk->start;
	n = stk->end;
	c = stk->r[0];
	while (i < n)
	{
		if (stk->r[i] > c)
			c = stk->r[i];
		i++;
	}
	return (c);
}

int	ffmin(t_stack *stk)
{
	int	i;
	int	n;
	int	c;

	i = stk->start;
	n = stk->end;
	c = stk->r[0];
	while (i < n)
	{
		if (stk->r[i] < c)
			c = stk->r[i];
		i++;
	}
	return (c);
}

int	findex(t_stack *stk, int percent)
{
	int	tmp;
	int	stop;
	int	size;
	int	j;
	int	s;

	s = stk->start;
	size = stk->end - stk->start;
	stop = size * percent / 100;
	while (s < stk->end)
	{
		j = 0;
		stk->check = 0;
		tmp = stk->r[s];
		while (j < stk->end)
		{
			if (tmp > stk->r[j])
				stk->check++;
			j++;
		}
		if (stk->check == stop - 1)
			return (tmp);
		s++;
	}
	return (0);
}
