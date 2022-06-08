/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:23:33 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 13:41:05 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ptr_hex(uintptr_t nbr)
{
	int	n;

	n = 0;
	if (nbr < 16)
	{
		if (nbr < 10)
			n += ft_putchar(nbr + '0');
		else
			n += ft_putchar('a' + nbr - 10);
	}
	if (nbr >= 16)
	{
		n += ptr_hex(nbr / 16);
		n += ptr_hex(nbr % 16);
	}
	return (n);
}

int	printadd(unsigned long long ptr)
{
	int	n;

	n = 0;
	n += ft_putstr("0x");
	if (ptr == 0)
		n += ft_putchar('0');
	else
		n += ptr_hex(ptr);
	return (n);
}

void	setnum(const char *flag, t_print *tab, int j, int i)
{
	tab->wdt = mo_atoi(flag, j);
	while (j < i)
	{
		if (flag[j] == '.')
		{
			tab->dot = 1;
			tab->prc = mo_atoi(flag, j + 1);
		}
		j++;
	}
}
