# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmuth <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 09:04:25 by jmuth             #+#    #+#              #
#    Updated: 2025/08/23 09:47:44 by jmuth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: hello

hello: hello.o main.o
	gcc -o hello hello.o main.o -g -Wall -Wextra -Werror

hello.o: hello.c
	gcc -o hello.o -c hello.c -g -Wall -Werror -Wextra 

main.o: main.c hello.h
	gcc -o main.o -c main.c -g -Wall -Werror -Wextra

fclean:
	rm -rf *.o
