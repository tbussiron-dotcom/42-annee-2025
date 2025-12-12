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

CC = cc

FLAGS = -Wall -Wextra -Werror 

INCLUDES = -Iincludes/ft.h

NAME = libft.a

SRCS =	srcs/ft_swap.c \
	srcs/ft_strcmp.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_putchar.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(INCLUDES) $@
	
.PHONY: all clean fclean re
