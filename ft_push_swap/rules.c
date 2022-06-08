/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:02:06 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 16:41:30 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atob(t_stack *a, t_stack *b)
{
	if (b->end == 0)
	{
		b->r[0] = a->r[0];
		b->end++;
		mvup(a);
	}
	else
	{
		mvdown(b);
		b->r[0] = a->r[0];
		mvup(a);
	}
	b->max = ffmax(b);
	b->min = ffmin(b);
	a->max = ffmax(a);
	a->min = ffmin(a);
	ft_printf("p%c\n", b->name);
	return (1);
}

int	swap(t_stack *stk)
{
	int	tmp;

	tmp = stk->r[0];
	stk->r[0] = stk->r[1];
	stk->r[1] = tmp;
	ft_printf("s%c\n", stk->name);
	return (1);
}

int	rotate(t_stack *stk)
{
	int	tmp;

	tmp = stk->r[0];
	mvup(stk);
	stk->end++;
	stk->r[stk->end - 1] = tmp;
	ft_printf("r%c\n", stk->name);
	return (1);
}

int	rev_rotate(t_stack *stk)
{
	int	tmp;

	tmp = stk->r[stk->end - 1];
	mvdown(stk);
	stk->r[stk->start] = tmp;
	stk->end--;
	ft_printf("rr%c\n", stk->name);
	return (1);
}

int	eval(t_stack *stk, int v)
{
	int	s;

	s = stk->start;
	while (s < stk->end)
	{
		if (stk->r[s] >= v)
			return (1);
		s++;
	}
	return (0);
}
