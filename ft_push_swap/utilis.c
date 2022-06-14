/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:39:08 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/14 14:50:14 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	printstk(t_stack *stk)
{
	int		i;

	i = stk->start;
	ft_printf("stack %c\n", stk->name);
	while (i < stk->end)
	{
		ft_printf("slot %d = %d\n", i, stk->r[i]);
		i++;
	}
	ft_printf("end stack\n");
}

size_t	ft_strlen(const char *s)
{
	size_t		ret;
	const char	*ptr;

	ret = 0;
	ptr = s;
	while (*ptr++)
		ret++;
	return (ret);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;

	ptr_d = dest;
	ptr_s = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n)
		while (n-- > 0)
			*ptr_d++ = *ptr_s++;
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < maxlen)
		ft_memcpy(dst, src, src_len + 1);
	else if (maxlen > 0)
	{
		ft_memcpy(dst, src, maxlen - 1);
		dst[maxlen - 1] = '\0';
	}
	return (ft_strlen(src));
}
