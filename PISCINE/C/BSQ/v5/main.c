/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:15:28 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/26 16:18:38 by thbussir         ###   ########.fr       */
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

void	solve_map(char *str, t_map map, t_square max)
{
	if (file_error_check(str) == 0)
		return ;
	map = get_map(str);
	if (map_error_check(map, str) == 0)
		return ;
	find_bsq(map, &max);
	display_map(map, max);
	free_map(map, map.height - 1);
	free(str);
}

int	main(int ac, char **av)
{
	int			i;
	char		**strs;
	t_map		map;
	t_square	max;

	i = 0;
	strs = malloc(ac * sizeof(char *));
	if (ac == 1)
	{
		strs[0] = read_term();
		ft_putstr("\n");
		solve_map(strs[0], map, max);
	}
	while (i < ac - 1)
	{
		strs[i] = read_file(av[i + 1]);
		solve_map(strs[i], map, max);
		if (i + 1 != ac - 1)
			ft_putstr("\n");
		i++;
	}
	free(strs);
	return (0);
}
