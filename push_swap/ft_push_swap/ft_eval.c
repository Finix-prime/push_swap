/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:20:50 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 13:41:15 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check2(char format, t_print *tab)
{
	long int		nb;
	unsigned int	nbr;

	if (format == 'd' || format == 'i')
	{
		nb = va_arg(tab->args, int);
		ft_putnbr(nb, tab);
		tab->len += num_count(nb);
	}
	else
	{
		nbr = va_arg(tab->args, unsigned int);
		ft_putnbr_un(nbr);
		tab->len += num_count_un(nbr);
	}
}

void	check(char format, t_print *tab)
{
	if (format == 'c')
		tab->len += ft_putchar(va_arg(tab->args, int));
	else if (format == 's')
		tab->len += ft_putstr(va_arg(tab->args, char *));
	else if (format == 'p')
		tab->len += printadd(va_arg(tab->args, uintptr_t));
	else if (format == 'd' || format == 'i' || format == 'u')
		check2(format, tab);
	else if (format == 'x' || format == 'X')
		tab->len += printhex(va_arg(tab->args, int), format);
	else if (format == '%')
		tab->len += ft_putchar('%');
}

void	ft_eval(const char *format, t_print *tab)
{
	char	*s;
	char	*src;

	format++;
	src = "cspdiuxX%";
	s = ft_strchr(src, *format);
	while (s == 0 && *format)
	{
		format++;
		s = ft_strchr(src, *format);
	}
	check(*s, tab);
}
