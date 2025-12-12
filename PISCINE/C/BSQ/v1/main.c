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

#include <stdlib.h>

void	free_strs(char **str, int len);
char	*read_file(char *file_name);

int	main(int ac, char **av)
{
	char	**strs;
	int	i;

	i = 0;
	strs = malloc(ac * sizeof(char*));
	while (i < ac - 1)
	{
		strs[i] = read_file(av[i + 1]);
		i++;
	}
	free_strs(strs, i - 1);
}
