/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:50:16 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/14 14:52:05 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
			len = ft_strlen(s2);
	else
		len = ft_strlen(s1);
	while (i <= len && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	stackcheck(t_stack *stk)
{
	int	i;

	i = stk->start;
	while (i < stk->end - 1)
	{
		if (stk->r[i] > stk->r[i + 1])
		{
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	ft_printf("OK\n");
}

void	find(t_stack *c1, t_stack *c2, char *str, int n)
{
	if (!ft_strncmp("sa", str, n))
		swap(c1);
	else if (!ft_strncmp("sb", str, n))
		swap(c2);
	else if (!ft_strncmp("ra", str, n))
		rotate(c1);
	else if (!ft_strncmp("rb", str, n))
		rotate(c2);
	else if (!ft_strncmp("rra", str, n))
		rev_rotate(c1);
	else if (!ft_strncmp("rrb", str, n))
		rev_rotate(c2);
	else if (!ft_strncmp("pb", str, n))
		atob(c1, c2);
	else if (!ft_strncmp("pa", str, n))
		atob(c2, c1);
}

void	readline(t_stack *c1, t_stack *c2)
{
	char	*str;
	char	*buf;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(char) * 100);
	if (!buf)
		return ;
	str = (char *)malloc(sizeof(char) * 100);
	if (!str)
		return ;
	while (read(0, buf, 1) > 0)
	{
		str[i] = *buf;
		i++;
		if (*buf == '\n')
		{
			find(c1, c2, str, ft_len(str));
			i = 0;
		}
	}
	free(str);
	free(buf);
}

int	main(int ac, char **av)
{
	t_stack	*c1;
	t_stack	*c2;

	c1 = (t_stack *)malloc(sizeof(t_stack));
	if (!c1)
		return (0);
	c2 = (t_stack *)malloc(sizeof(t_stack));
	if (!c2)
		return (0);
	c1 = setstack(c1, 'x');
	c2 = setstack(c2, 'y');
	if (ac > 1)
		init(c1, ac, av);
	if (errorhandling(c1) == 0)
		return (0);
	readline(c1, c2);
	stackcheck(c1);
	return (0);
}
