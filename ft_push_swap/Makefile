# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmethira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 12:41:12 by pmethira          #+#    #+#              #
#    Updated: 2022/06/10 16:25:14 by pmethira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
FLAGS	= 	-Wall -Wextra -Werror -I

NAME = push_swap
SRC = *.c
HEAD = push_swap.h
ARG = `ruby -e "puts (0..9).to_a.shuffle.join(' ')"`
run = ./push_swap $(ARG) | wc -l
runs = ./push_swap $(ARG)

all:
	@$(CC) -g $(FLAGS) $(HEAD) $(SRC) -o $(NAME)
	@$(runs)

clean:
	@rm -rf *.dSYM
	@rm -rf $(OBJ_DIR_PRINTF)
	@rm -rf a.out

fclean:	clean
	@rm -rf $(NAME)
