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

#include <stdio.h>

int	draw_squares(t_map map, t_square square, int startl, int startc)
{
	int	l;
	int	c;
	int	size;

	l = startl;
	c = startc;
	size = 0;
	while (map.lines[l][c] != map.obstacle && l < map.height && c < map.length)
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
		printf("%s%d\n", "c = ", c);
		printf("%s%d\n\n", "l = ", l);
	}
	return (0);
}

int main()
{
	draw_squares(0, 0);
	return 0;
}
