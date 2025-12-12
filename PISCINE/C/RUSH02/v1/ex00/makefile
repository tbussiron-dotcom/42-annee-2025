# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmuth <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 14:37:45 by jmuth             #+#    #+#              #
#    Updated: 2025/08/23 15:52:53 by jmuth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rush-02: ft_strlen.o ft_write.o ft_check.o ft_dict_in_tab.o main.o
	cc -o rush-02 ft_strlen.o ft_write.o ft_check.o ft_dict_in_arr.o main.o -g -Wall -Werror -Wextra

ft_strlen.o: ft_strlen.c
	cc -o ft_strlen.o -c ft_strlen.c -g -Wall -Werror -Wextra 

ft_write.o: ft_write.c
	cc -o ft_write.o -c ft_write.c -g -Wall -Werror -Wextra

ft_check.o: ft_check.c
	cc -o ft_check.o -c ft_write.c -g -Wall -Wextra -Werror

ft_dict_in_array.o: ft_dict_in_tab.c
	cc -o ft_dict_in_arr.o -c ft_dict_in_arr.c -g -Wall -Werror -Wextra 

main.o: main.c rush02.h
	cc -o main.o -c main.c -g -Wall -Werror -Wextra 

fclean:
	rm -rf *.o
