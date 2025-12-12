/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljouault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:45:01 by ljouault          #+#    #+#             */
/*   Updated: 2025/08/27 09:45:03 by ljouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_map(t_map map, t_square max)
{
	int	l;
	int	c;

	l = 0;
	while (l < map.height)
	{
		c = 0;
		while (c < map.length)
		{
			if (l >= max.startl && l < max.startl + max.size
				&& c >= max.startc && c < max.startc + max.size)
				write(1, &map.occupied, 1);
			else
				write(1, &map.lines[l][c], 1);
			c++;
		}
		ft_putstr("\n");
		l++;
	}
}
