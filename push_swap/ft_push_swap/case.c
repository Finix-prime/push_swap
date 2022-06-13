/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:12:52 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/11 19:37:48 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case1(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += swap(a);
	count += rotate(a);
	count += pullb(a, b);
	return (count);
}

int	case2(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += swap(a);
	count += pullb(a, b);
	return (count);
}

int	case3(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += rev_rotate(a);
	count += pullb(a, b);
	return (count);
}

int	case4(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += rotate(a);
	count += pullb(a, b);
	return (count);
}

int	case5(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += rotate(a);
	count += swap(a);
	count += pullb(a, b);
	return (count);
}
