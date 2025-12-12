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

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	**strs;
	t_map	map;

	i = 0;
	strs = malloc(ac * sizeof(char *));
	while (i < ac - 1)
	{
		strs[i] = read_file(av[i + 1]);
		if (!strs[i])
		{
			free(strs);
			return (0);
		}
		map = get_map(strs[i]);
		if (map.height == 0)
		{
			free(strs[i]);
			free(strs);
			ft_putstr(NULL);
			return (0);
		}
		j = 0;
		while (j < map.height)
		{
			ft_putstr(map.lines[j]);
			ft_putstr("\n");
			j++;
		}
		if (i + 1 != ac - 1)
			ft_putstr("\n");
		free_map(map, map.height - 1);
		i++;
	}
	free_strs(strs, i - 1);
	return (0);
}
