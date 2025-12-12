/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljouault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:35:45 by ljouault          #+#    #+#             */
/*   Updated: 2025/08/26 09:40:56 by ljouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	update_square(t_square *max, int size, int startl, int startc)
{
	max->size = size;
	max->startc = startc;
	max->startl = startl;
}

static t_square	draw_square(t_map map, t_square *max, int startl, int startc)
{
	int			l;
	int			c;
	int			size;
	t_square	last_obstacle;

	l = startl;
	c = startc;
	size = 0;
	while (l < map.height && c < map.length && map.lines[l][c] != map.obstacle)
	{
		if (l < startl + size && c == startc + size)
			l++;
		else if (l == startl + size && c > startc)
			c--;
		else if (l == startl + size && c == startc)
		{
			size++;
			c = startc + size;
			l = startl;
		}
	}
	if (size > max->size)
		update_square(max, size, startl, startc);
	update_square(&last_obstacle, 1, l, c);
	return (last_obstacle);
}

void	find_bsq(t_map map, t_square *max)
{
	int			startl;
	int			startc;
	int			size;
	t_square	last_obstacle;

	startl = 0;
	startc = 0;
	size = 0;
	if (map.height == 1)
		size = 1;
	update_square(max, size, startl, startc);
	last_obstacle = draw_square(map, max, startl, startc);
	while (startl + 1 + max->size < map.height
		&& startc + 1 + max->size <= map.length)
	{
		if (last_obstacle.startc + 1 + max->size < map.length)
			startc = last_obstacle.startc + 1;
		else if (startl + 1 + max->size < map.height)
		{
			startc = 0;
			startl++;
		}
		last_obstacle = draw_square(map, max, startl, startc);
	}
}
