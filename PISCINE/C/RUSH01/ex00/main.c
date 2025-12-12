/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:31:37 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/17 20:32:59 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	parse_args(char *str, int *sides);
int	solve(int grid[4][4], int *sides, int pos);

int	main(int ac, char **av)
{
	int	grid[4][4];
	int	sides[16];
	int	i;
	int	j;

	if (ac != 2 || parse_args(av[1], sides))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!solve(grid, sides, 0))
		write(1, "Error\n", 6);
	return (0);
}
