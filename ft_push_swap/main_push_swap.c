/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:34:51 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/13 15:35:11 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
