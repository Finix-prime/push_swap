# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmethira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 12:41:12 by pmethira          #+#    #+#              #
#    Updated: 2022/06/11 19:39:15 by pmethira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
FLAGS	= 	-Wall -Wextra -Werror -I

NAME = push_swap
# LIB = libftprintf.a
SRC = rules.c sort.c sort2.c utilis.c utilis2.c utilis3.c case.c push_swap.c
HEAD = push_swap.h
ARG = `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
run = ./push_swap $(ARG) | wc -l
runs = ./push_swap $(ARG)
SRCS = $(shell find . -name 'ft*.c')
# OBJS = $(SRCS:%.c=%.o)

# all:	$(NAME)

# $(NAME): $(OBJS)
# 	@ar -crs $(LIB) $(OBJS)
# 	@$(CC) -g $(FLAGS) $(HEAD) $(SRC) -o $(NAME) -L libftprintf
# 	@$(run)

all :
		@$(CC) -g $(FLAGS) $(HEAD) $(SRC) $(SRCS) -o $(NAME)
		@$(runs)

clean:
	@rm -rf *.dSYM
	@rm -rf *.gch
	@rm -rf a.out
	@rm -rf *.o

fclean:	clean
	@rm -rf $(NAMES)
	@rm -rf *.a

norm:
	@norminette -R CheckForbiddenSourceHeader

.PHONY:		all clean fclean re norm

