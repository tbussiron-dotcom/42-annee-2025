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

NAME = push_swap
BONUS = checker

SRCS = \
	srcs/push_swap.c \
	srcs/parsing.c \
	srcs/stack_utils.c \
	srcs/operations.c \
	srcs/stack_creation.c \
	srcs/stack_utils_2.c \
	srcs/pre_sort.c

SRCS_BONUS = \
	srcs/checker/checker.c \
	srcs/checker/checker_operations.c \
	srcs/checker/get_next_line.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = libs/libft/libft.a
PRINTF = libs/ft_printf/libftprintf.a
LIBS = $(PRINTF) $(LIBFT)

all: $(NAME)

# -------- EXECUTABLE PRINCIPAL -------- #

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

# -------- BONUS -------- #

# Tous les objets sauf push_swap.o + les objets bonus
CHECKER_OBJS = $(filter-out srcs/push_swap.o, $(OBJS)) $(OBJS_BONUS)

$(BONUS): $(LIBS) $(CHECKER_OBJS)
	$(CC) $(FLAGS) $(CHECKER_OBJS) $(LIBS) -o $(BONUS)

bonus: $(BONUS)

# -------- LIBRARIES COMPILATION -------- #

$(LIBFT):
	make -C libs/libft

$(PRINTF):
	make -C libs/ft_printf

# -------- GENERAL RULES -------- #

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(CHECKER_OBJS)
	make -C libs/libft clean
	make -C libs/ft_printf clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C libs/libft fclean
	make -C libs/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
