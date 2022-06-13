/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:36:38 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/08 13:41:38 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	int	n;

	n = write(1, &c, 1);
	return (n);
}

int	ft_putstr(char *s)
{
	char	*p;
	int		n;

	n = 0;
	p = s;
	if (!s)
		p = "(null)";
	while (*p)
	{
		n += ft_putchar(*p);
		p++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != (char)c)
	{
		if (*p == '\0')
		{
			return (0);
		}
		p++;
	}
	return (p);
}

int	mo_atoi(const char *str, int i)
{
	int		ans;

	ans = 0;
	while (str[i] < '1' || str[i] > '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	return (ans);
}
