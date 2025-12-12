/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:58:22 by lemartin          #+#    #+#             */
/*   Updated: 2025/08/17 11:54:27 by lemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int grid[4][4], int r, int c, int n);
int	check_grid(int grid[4][4], int *sides);

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	solve(int grid[4][4], int *sides, int pos)
{
	int	r;
	int	c;
	int	n;

	if (pos == 16)
		return (check_grid(grid, sides));
	r = pos / 4;
	c = pos % 4;
	n = 1;
	while (n <= 4)
	{
		if (is_valid(grid, r, c, n))
		{
			grid[r][c] = n;
			if (solve(grid, sides, pos + 1))
				return (1);
			grid[r][c] = 0;
		}
		n++;
	}
	return (0);
}

int	parse_args(char *str, int *sides)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i > 30)
			return (1);
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (j >= 16)
				return (1);
			sides[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	if (j != 16)
		return (1);
	return (0);
}
