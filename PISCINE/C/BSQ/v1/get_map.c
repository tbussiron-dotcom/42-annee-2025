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

void	free_map(struct s_map map, int n)
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

void	fill_line(struct s_map map, int line, char *str, int start)
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

int	fill_map(struct s_map map, char *str)
{
	int	i;
	int	start;

	i = 0;
	start = 5;
	while (i < map.height)
	{
		map.lines[i] = (char *)malloc((map.length + 1) * sizeof(char));
		if (!map.lines[i])
		{
			free_map(map, i - 1);
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

	if (!map_is_valid(str))
	{	
		map.height = 0;
		return (map);
	}
	map.height = str[0] - '0';
	map.length = line_length(str, 5);
	map.empty = str[1];
	map.obstacle = str[2];
	map.occupied = str[3];
	map.lines = (char **)malloc((map.height + 1) * sizeof(char *));
	if (!map.lines)
		return (map);
	map.lines[0] = NULL;
	if (!(fill_map(map, str)))
		return (map);
	map.lines[map.height] = NULL;
	return (map);
}

#include <stdio.h>

int	main()
{
	char str[] = "3.ox\no.o.o.o\n.o.o.o.\no.o.x.o\n";
	struct s_map map = get_map(str);
	if (map.height == 0)
	{
		printf("%s\n", "map error");
		return 0;
	}
	printf("%d   %d\n", map.height, map.length);
	printf("%c%c%c\n", map.empty, map.obstacle, map.occupied);
	int i = 0;
	while (i < map.height)
	{
		printf("%s\n", map.lines[i]);
		i++;
	}
	free_map(map, map.height - 1);
	return 0;
}
