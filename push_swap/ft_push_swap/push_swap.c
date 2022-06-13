/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:33:07 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/13 15:34:47 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign(t_stack *stk, char **tmp, int j, int k)
{
	ft_isalpha(*tmp[k]);
	stk->r[j] = ft_atoi(tmp[k]);
	if (stk->r[j] > stk->max)
		stk->max = stk->r[j];
	if (stk->r[j] < stk->min)
		stk->min = stk->r[j];
	return (1);
}

int	init(t_stack *stk, int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 1;
	j = 0;
	stk->max = ft_atoi(av[1]);
	stk->min = ft_atoi(av[1]);
	while (i < ac)
	{
		k = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[k])
		{
			if (!(assign(stk, tmp, j, k)))
				return (0);
			j++;
			k++;
		}
		i++;
	}
	stk->end = j;
	return (1);
}

int	errorhandling(t_stack *stk)
{
	int	tmp;
	int	i;
	int	j;
	int	n;

	j = 0;
	while (j < stk->end)
	{
		i = 0;
		n = 0;
		tmp = stk->r[j];
		while (i < stk->end)
		{
			if (tmp == stk->r[i])
				n++;
			i++;
		}
		if (n > 1)
			error();
		j++;
	}
	return (1);
}
