/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:33:05 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/26 17:38:09 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
//#include <stdib.h>
#include <stdio.h>

t_square	check_squares(t_map map, int lin, int col)
{
	t_square square;
	int		square_size;
	int		check_l;
	int		check_c;

	square_size = 2;
	while (map.lines[lin][col] != map.obstacle 
		&& check_l < map.height && check_c < map.length)
	{
		if (check_l == lin && check_c == col)
			square_size++;
		else if (check_c == col && check_l != lin)
			check_l--;
		else if (check_l == lin + square_size)
			check_c--;
		else if (check_c == col + square_size)
			check_l++;
		else if (check_l == lin)
			check_c++;
		printf("col = %d, lin = %d", check_c, check_l);
	}
	return (square);
}

/*s_square	check_map(s_map map)
{
	t_square	square_max;
	int	lin;
	int	col;

	lin = 0;
	while (map.lines[lin])
	{
		col = 0;
		while (map.lines[lin][col])
		{
			if (map.lines[lin][col] == map.empty)
				check_squares(map, lin, col);
				// if return > biggest square, biggest square = return
				// 	square_max = return square
			col++;
		}
		lin++;
	}
	// if !square_max, return error
	return (square_max);
}*/

void	free_strs(char **str, int len);
char	*read_file(char *file_name);

int	main(int ac, char **av)
{
	char	**strs;
	int	i;

	i = 0;
	strs = malloc(ac * sizeof(char*));
	while (i < ac - 1)
	{
		strs[i] = read_file(av[i + 1]);
		i++;
	}
	check_squares(strs[0], 0, 0);
	free_strs(strs, i - 1);
}
