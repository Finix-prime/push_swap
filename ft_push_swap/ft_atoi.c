/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:57:58 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/11 19:40:43 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				pre;
	long long int	ans;

	i = 0;
	pre = 1;
	ans = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pre = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	if (ans < -2147483648 || ans > 2147483647)
		return (0);
	return (pre * ans);
}

int	check5(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->end - 2)
	{
		if (stk->r[i] > stk->r[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	cases(t_stack *a, t_stack *b)
{
	int	count;

	if (a->r[0] < a->r[1] && a->r[1] > a->r[2] && a->r[0] < a->r[2])
		count = case1(a, b);
	else if (a->r[0] > a->r[1] && a->r[1] < a->r[2] && a->r[0] < a->r[2])
		count = case2(a, b);
	else if (a->r[0] < a->r[1] && a->r[1] > a->r[2] && a->r[0] > a->r[2])
		count = case3(a, b);
	else if (a->r[0] > a->r[1] && a->r[1] < a->r[2] && a->r[0] > a->r[2])
		count = case4(a, b);
	else if (a->r[0] > a->r[1] && a->r[1] > a->r[2] && a->r[0] > a->r[2])
		count = case5(a, b);
	else
		count = pullb(a, b);
	return (count);
}

int	pullb(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += atob(b, a);
	count += atob(b, a);
	count += rotate(a);
	return (count);
}

int	wherenum(t_stack *stk, int x)
{
	int	i;

	i = 0;
	stk->at[0] = 0;
	stk->at[1] = 0;
	while (i < stk->end)
	{
		if (stk->r[i] == x)
			break ;
		i++;
	}
	if (i <= stk->end / 2)
		stk->at[0] = 1;
	else if (i > stk->end / 2)
		stk->at[1] = 1;
	return (stk->r[i]);
}
