/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:29:13 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 13:41:28 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int nb, t_print *tab)
{
	if (nb == -2147483648)
	{
		tab->len += ft_putstr("-2147483648");
		return ;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else if (nb < 0 && nb > -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(-nb, tab);
	}
	else
	{
		ft_putnbr(nb / 10, tab);
		ft_putnbr(nb % 10, tab);
	}
}

int	num_count(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (i);
	else if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	else if (nb == 0)
		i++;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
