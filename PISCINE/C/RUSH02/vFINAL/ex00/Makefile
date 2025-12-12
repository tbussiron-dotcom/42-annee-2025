# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmuth <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 20:39:37 by jmuth             #+#    #+#              #
#    Updated: 2025/08/24 21:09:41 by jmuth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
INC_FILE=	-Irush02.h
EXEC	=	rush-02

SRC_FILES=	main.c \
		dict_in_str.c \
      	 	ft_check_nb.c \
	       ft_print.c \
	       ft_putstr.c \
	       ft_search.c \
	       ft_search_class.c \
	       ft_strlen.c \
	       ft_strstr.c \
	       ft_write_nb.c \
	       increment.c

OBJ_FILES=	$(SRC_FILES:%.c=%.o)

all: $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INC_FILES) $(OBJ_FILES) -o $@ 

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
