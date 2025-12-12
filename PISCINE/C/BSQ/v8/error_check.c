/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljouault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:42:07 by ljouault          #+#    #+#             */
/*   Updated: 2025/08/27 16:42:11 by ljouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	map_error_check(t_map map, char *strs)
{
	if (map.height == 0)
	{
		free(strs);
		ft_putstr("map error\n");
		return (0);
	}
	return (1);
}

int	file_error_check(char *strs)
{
	if (!strs)
	{
		ft_putstr("map error\n");
		free(strs);
		return (0);
	}
	return (1);
}
