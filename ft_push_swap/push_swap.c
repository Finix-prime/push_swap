/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:33:07 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/12 15:30:40 by pmethira         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	int		count;

	count = 0;
	sta = (t_stack *)malloc(sizeof(t_stack));
	if (!sta)
		return (0);
	stb = (t_stack *)malloc(sizeof(t_stack));
	if (!stb)
		return (0);
	sta = setstack(sta, 'a');
	stb = setstack(stb, 'b');
	if (ac > 1)
		init(sta, ac, av);
	if (errorhandling(sta) == 0)
		return (0);
	count = sortstack(sta, stb);
	free(sta);
	free(stb);
	return (0);
}
