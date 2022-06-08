/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:20:06 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 13:41:51 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_print	*set(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->pad0 = 0;
	tab->dot = 0;
	tab->dash = 0;
	tab->len = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->per = 0;
	tab->sp = 0;
	tab->sharp = 0;
	tab->len = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		ret;

	ret = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (0);
	tab = set(tab);
	va_start(tab->args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *format)
		{
			ft_eval(format, tab);
			format++;
		}
		else if (*format != '%' && *format)
			ret += ft_putchar(*format);
		format++;
	}
	va_end(tab->args);
	ret += tab->len;
	free(tab);
	return (ret);
}
/*
int main(void)
{
     int     n = 0;

     n = ft_printf("%p %s %c %d %x\n",&n, "finix", 'z', 42, 1234);
     ft_printf("\ntotal lenght return (ans) = %d\n",n);
     ft_printf("\n");
     return (0);
 }*/
