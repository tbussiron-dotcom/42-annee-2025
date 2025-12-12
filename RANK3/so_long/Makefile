# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbastiat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 20:25:56 by jbastiat          #+#    #+#              #
#    Updated: 2025/08/24 21:27:43 by jbastiat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -I includes

NAME = so_long

SRCS = srcs/so_long.c srcs/get_next_line.c
OBJS = $(SRCS:.c=.o)

LIBFT = libs/libft/libft.a
PRINTF = libs/ft_printf/libftprintf.a
LIBS = $(PRINTF) $(LIBFT)

MLX = MacroLibX/libmlx.so
SDL = -lSDL2

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) $(MLX) $(SDL) -o $(NAME)

$(LIBFT):
	make -C libs/libft

$(PRINTF):
	make -C libs/ft_printf

clean:
	rm -f $(OBJS)
	make -C libs/libft clean
	make -C libs/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean
	make -C libs/ft_printf fclean

re: fclean all

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: re all clean fclean
