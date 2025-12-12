/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:35:44 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/24 21:29:26 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*strs;

	if (ac == 2)
	{
		if (ft_check_zero(av[1]) == 1)
		{
			write(1, "zero", 4);
			return (0);
		}
		if (ft_check_nb(av[1]) == 1)
			return (0);
		strs = dict_in_str(&strs);
		ft_write_nb(av[1], strs);
	}
	return (0);
}
