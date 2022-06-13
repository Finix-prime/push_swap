/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:03:19 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 16:33:46 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mvup(t_stack *stk)
{
	int	s;
	int	n;

	s = stk->start;
	n = stk->end;
	while (s < n - 1)
	{
		stk->r[s] = stk->r[s + 1];
		s++;
	}
	stk->end -= 1;
}

void	mvdown(t_stack *stk)
{
	int	s;
	int	n;

	s = stk->start;
	stk->end++;
	n = stk->end;
	while (n > s)
	{
		stk->r[n] = stk->r[n - 1];
		n--;
	}
}

void	marker(t_stack *stk)
{
	stk->mark[0] = ffmax(stk);
	stk->mark[1] = findex(stk, 80);
	stk->mark[2] = findex(stk, 60);
	stk->mark[3] = findex(stk, 40);
	stk->mark[4] = findex(stk, 20);
	stk->mark[5] = ffmin(stk);
}

int	pcheck(t_stack *stk, int v)
{
	int	s;
	int	n;

	s = stk->start;
	n = stk->end - 1;
	stk->at[0] = 0;
	stk->at[1] = 0;
	while (s < n)
	{
		if (stk->r[s] >= v)
		{
			stk->at[0] = 1;
			return (stk->r[s]);
		}
		else if (stk->r[n] >= v)
		{
			stk->at[1] = 1;
			return (stk->r[n]);
		}
		s++;
		n--;
	}
	return (0);
}

int	pcheck2(t_stack *stk)
{
	int	s;
	int	n;

	s = stk->start;
	n = stk->end - 1;
	stk->at[0] = 0;
	stk->at[1] = 0;
	while (stk->r[s] != ffmax(stk) && stk->r[n] != ffmax(stk))
	{
		s++;
		n--;
	}
	if (stk->r[s] == ffmax(stk))
	{
		stk->at[0] = 1;
		return (stk->r[s]);
	}
	if (stk->r[n] == ffmax(stk))
	{
		stk->at[1] = 1;
		return (stk->r[n]);
	}
	return (0);
}
