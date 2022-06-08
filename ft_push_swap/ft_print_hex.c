/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:26:43 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 13:41:23 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	printhex(int nb, char format)
{
	char		*list;
	char		*listupper;
	long int	nbr;
	int			n;

	list = "0123456789abcdef";
	listupper = "0123456789ABCDEF";
	if (format == 'X')
		list = listupper;
	n = 0;
	nbr = nb;
	if (nbr < 0)
		nbr = 4294967296 + nbr;
	if (nbr < 16)
		n += ft_putchar(list[nbr]);
	if (nbr >= 16)
	{
		n += printhex(nbr / 16, format);
		n += printhex(nbr % 16, format);
	}
	return (n);
}
