# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmuth <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 16:04:37 by jmuth             #+#    #+#              #
#    Updated: 2025/08/24 17:05:12 by jmuth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror -g
INC=rush02.h
SRC=src/
EXEC=rush-02
OBJ= $SRC:(.c = .o)
all: $(EXEC)

all: $(SRC)main.c $(SRC)operation.o 
    $(CC) $(INC) -o $(SRC)$@ $^ $(CFLAGS) 

$(SRC)%.o : $(SRC)%.c
    $(CC) $(INC) -o $@ -c $< $(CFLAGS)


re fclean all
