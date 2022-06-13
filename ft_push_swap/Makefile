# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmethira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 12:41:12 by pmethira          #+#    #+#              #
#    Updated: 2022/06/13 10:26:18 by pmethira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
FLAGS	= 	-Wall -Wextra -Werror -I

NAME = libftprintf.a
PROGRAME = push_swap
SRC = rules.c sort.c sort2.c sort3.c utilis.c utilis2.c utilis3.c case.c push_swap.c ft_atoi.c ft_split.c
HEAD = push_swap.h

exe = ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; echo $$ARG >> test.txt; ./push_swap $$ARG
checker = ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; echo $$ARG >> test.txt; ./push_swap $$ARG | ./checker $$ARG
exe5 = ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; echo $$ARG >> test.txt
exe100 = ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; echo $$ARG >> test.txt
exe500 = ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; echo $$ARG >> test.txt

SRCS = ft_eval.c ft_print_address.c ft_print_hex.c ft_print_num.c ft_print_unsigned.c ft_print_utilis.c ft_printf.c
OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(FLAGS) $(HEAD) -c $< -o $@


$(NAME): $(OBJS)
	@ar -crs $(NAME) $(OBJS)
	@$(CC) -g $(FLAGS) $(HEAD) $(SRC) $(SRCS) -o $(PROGRAME)
	@touch log.txt

all :	$(NAME)

clean:
	@rm -rf *.dSYM
	@rm -rf *.gch
	@rm -rf a.out
	@rm -rf *.o
	@rm -rf test.txt

fclean:	clean
	@rm -rf $(NAMES)
	@rm -rf $(PROGRAME)
	@rm -rf *.a
	@rm -rf *.txt

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader

5:
	@$(exe5)

100:
	@$(exe100)

500:
	@$(exe500)

test:
	@$(exe)

checker:
	@$(checker)

.PHONY:		all clean fclean re norm

