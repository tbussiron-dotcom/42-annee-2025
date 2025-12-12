/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkloutz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:08:09 by stkloutz          #+#    #+#             */
/*   Updated: 2025/08/24 20:45:37 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush02.h"

int	ft_check_zero(char *nbr)
{
	int	i;
	int	is_zero;

	i = 0;
	is_zero = 1;
	while (nbr[i])
	{
		if (nbr[i] != '0')
			is_zero = 0;
		i++;
	}
	return (is_zero);
}

void	ft_write_error(int err)
{
	if (err == 1)
		write(2, "Error\n", 6);
	else if (err == 2)
		write(2, "Dict Error\n", 11);
	return ;
}

int	ft_check_nb(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		ft_write_error(1);
		return (1);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || i > 39)
		{
			ft_write_error(1);
			return (1);
		}
		i++;
	}
	return (0);
}
