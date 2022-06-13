/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <pmethira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:50:16 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/13 16:35:06 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

// int	ft_strlen(char *str)
// {
// 	int	i;
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

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

void	find(t_stack *c1, t_stack *c2,char *str, int n)
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
	printstk(c1);
}

void	readline(t_stack *c1, t_stack *c2)
{
	char *str;
	char *buf;

	str = (char *)malloc(sizeof(char) * 100);
	if (!str)
		return ;
	buf = (char *)malloc(sizeof(char) * 100);
	if (!buf)
		return ;
	while (read(0, buf, 1) > 0)
	{
		if (*buf == '\n')
			break ;
		*str = *buf;
	}
	find(c1, c2,str, ft_strlen(str));
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
	c1 = setstack(c1, '1');
	c2 = setstack(c2, '2');
	if (ac > 1)
		init(c1, ac, av);
	if (errorhandling(c1) == 0)
		return (0);
	readline(c1, c2);
	return (0);
}
