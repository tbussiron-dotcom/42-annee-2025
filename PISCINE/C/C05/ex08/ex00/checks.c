/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:47:50 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/17 20:47:53 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_grid(int grid[4][4]);

int	count_visible(int *line, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_row(int grid[4][4], int *sides, int r)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[r][3 - i];
		i++;
	}
	if (count_visible(line, 4) != sides[12 + r])
		return (1);
	return (0);
}

int	check_col(int grid[4][4], int *sides, int c)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][c];
		i++;
	}
	if (count_visible(line, 4) != sides[c])
		return (1);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[3 - i][c];
		i++;
	}
	if (count_visible(line, 4) != sides[4 + c])
		return (1);
	return (0);
}

int	is_valid(int grid[4][4], int r, int c, int n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[r][i] == n || grid[i][c] == n)
			return (0);
		i++;
	}
	return (1);
}

int	check_grid(int grid[4][4], int *sides)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		if (check_row(grid, sides, r))
			return (0);
		r++;
	}
	c = 0;
	while (c < 4)
	{
		if (check_col(grid, sides, c))
			return (0);
		c++;
	}
	print_grid(grid);
	return (1);
}
