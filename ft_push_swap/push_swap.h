/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmethira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:22 by pmethira          #+#    #+#             */
/*   Updated: 2022/06/12 15:29:19 by pmethira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct l_list
{
	char	name;
	int		start;
	int		end;
	int		r[500];
	int		c[100];
	int		max;
	int		min;
	int		at[2];
	int		mark[20];
	int		check;
}	t_stack;

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		pad0;
	int		dot;
	int		dash;
	int		len;
	int		sign;
	int		is_zero;
	int		per;
	int		sp;
	int		sharp;
}	t_print;

t_stack	*setstack(t_stack *a, char n);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		len(char *s);
int		ffmax(t_stack *stk);
int		findex(t_stack *stk, int percent);
int		ffmin(t_stack *stk);
int		swap(t_stack *stk);
int		rotate(t_stack *stk);
int		rev_rotate(t_stack *stk);
int		eval(t_stack *stk, int v);
int		pcheck(t_stack *stk, int v);
int		pcheck2(t_stack *stk);
int		mean(t_stack *stk, int i);
int		kick(t_stack *a, t_stack *b, int x, int mean);
int		kick2(t_stack *a, t_stack *b, int x);
int		atob(t_stack *a, t_stack *b);
int		deck1(t_stack *a, t_stack *b);
int		deck2(t_stack *a, t_stack *b);
int		deck3(t_stack *a, t_stack *b);
int		deck4(t_stack *a, t_stack *b);
int		deck5(t_stack *a, t_stack *b);
int		sort(t_stack *a, t_stack *b);
int		sortstack(t_stack *a, t_stack *b);
int		errorhandling(t_stack *stk);
int		assign(t_stack *stk, char **tmp, int j, int k);
int		init(t_stack *stk, int ac, char **av);
int		check5(t_stack *stk);
int		sort5(t_stack *a, t_stack *b);
int		cases(t_stack *a, t_stack *b);
int		pullb(t_stack *a, t_stack *b);
int		case1(t_stack *a, t_stack *b);
int		case2(t_stack *a, t_stack *b);
int		case3(t_stack *a, t_stack *b);
int		case4(t_stack *a, t_stack *b);
int		case5(t_stack *a, t_stack *b);
int		wherenum(t_stack *stk, int x);
int		deck10(t_stack *a, t_stack *b);
void	error(void);
void	ft_isalpha(int c);
void	marker10(t_stack *stk);
void	printstk(t_stack *stk);
void	mvup(t_stack *stk);
void	mvdown(t_stack *stk);
void	marker(t_stack *stk);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen);
char	*ft_strchr(const char *s, int c); ///////////////////////////////////
int		printhex(int nb, char format);
int		ft_printf(const char *format, ...);
int		mo_atoi(const char *str, int i);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		num_count_un(unsigned int nb);
int		num_count(int nb);
int		ptr_hex(uintptr_t nbr);
int		printadd(unsigned long long ptr);
void	ft_eval(const char *format, t_print *tab);
void	ft_putnbr(int nb, t_print *tab);
void	ft_putnbr_un(unsigned int nb);
void	set_flag(const char *flag, t_print *tab, int j, int i);
void	setnum(const char *flag, t_print *tab, int j, int i);
void	check2(char format, t_print *tab);
void	check(char format, t_print *tab);//////////////////////////////////

#endif
