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

FLAGS = -Wall -Wextra -Werror -g -I includes

NAME = pipex

BONUS = checker

SRCS = srcs/pipex.c

#SRCS_BONUS = srcs/checker/checker.c	srcs/checker/checker_operations.c srcs/checker/get_next_line.c

LIBS = libs/libftprintf.a libs/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CHECKER_OBJS = $(filter-out srcs/push_swap.o, $(OBJS)) $(OBJS_BONUS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	
#$(BONUS): $(CHECKER_OBJS)
	$(CC) $(FLAGS) $(CHECKER_OBJS) $(LIBS) -o $(BONUS)

#bonus: $(BONUS)


.PHONY: re all clean fclean
