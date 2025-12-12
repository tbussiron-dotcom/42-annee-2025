/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljouault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:57:18 by ljouault          #+#    #+#             */
/*   Updated: 2025/08/26 10:56:08 by ljouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_map(t_map map, int n)
{
	int	i;

	i = n;
	while (i >= 0)
	{
		free(map.lines[i]);
		i--;
	}
	free(map.lines);
}

static void	fill_line(t_map map, int line, char *str, int start)
{
	int	j;

	j = 0;
	while (j < map.length)
	{
		map.lines[line][j] = str[j + start];
		j++;
	}
	map.lines[line][j] = '\0';
}

static int	fill_map(t_map map, char *str)
{
	int	i;
	int	start;

	i = 0;
	start = line_length(str, 0) + 1;
	while (i < map.height)
	{
		map.lines[i] = (char *)malloc((map.length + 1) * sizeof(char));
		if (!map.lines[i])
		{
			free_map(map, i - 1);
			map.height = 0;
			return (0);
		}
		map.lines[i][0] = '\0';
		fill_line(map, i, str, start);
		i++;
		start += map.length + 1;
	}
	return (1);
}

struct s_map	get_map(char *str)
{
	struct s_map	map;
	int				first_line_length;

	if (!map_is_valid(str))
	{
		map.height = 0;
		return (map);
	}
	first_line_length = line_length(str, 0);
	map.height = ft_atoi(str, first_line_length);
	map.length = line_length(str, first_line_length + 1);
	map.empty = str[first_line_length - 3];
	map.obstacle = str[first_line_length - 2];
	map.occupied = str[first_line_length - 1];
	map.lines = (char **)malloc((map.height + 1) * sizeof(char *));
	if (!map.lines)
	{
		map.height = 0;
		return (map);
	}
	map.lines[0] = NULL;
	if (!(fill_map(map, str)))
		return (map);
	map.lines[map.height] = NULL;
	return (map);
}
