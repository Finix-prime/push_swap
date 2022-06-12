/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:49:03 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/12 15:33:51 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		error();
}

void	error(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	marker10(t_stack *stk)
{
	stk->mark[0] = ffmax(stk);
	stk->mark[1] = findex(stk, 90);
	stk->mark[2] = findex(stk, 80);
	stk->mark[3] = findex(stk, 70);
	stk->mark[4] = findex(stk, 60);
	stk->mark[5] = findex(stk, 50);
	stk->mark[6] = findex(stk, 40);
	stk->mark[7] = findex(stk, 30);
	stk->mark[8] = findex(stk, 20);
	stk->mark[9] = findex(stk, 10);
	stk->mark[10] = ffmin(stk);
}

int	deck10(t_stack *a, t_stack *b)
{
	int	i;
	int	x;
	int	count;
	int	means;

	count = 0;
	i = 1;
	marker10(a);
	while (i < 11 && a->end > 0)
	{
		while (eval(a, a->mark[i]) != 0 && a->end > 0)
		{
			means = mean(a, i);
			x = pcheck(a, a->mark[i]);
			if (x == 0)
				x = ffmin(a);
			count += kick(a, b, x, means);
		}
		i++;
	}
	return (count);
}
