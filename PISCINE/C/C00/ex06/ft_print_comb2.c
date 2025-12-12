/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:46:02 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/06 19:02:53 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(int nb)
{
	char	chr;

	chr = nb / 10 + '0';
	write (1, &chr, 1);
	chr = nb % 10 + '0';
	write (1, &chr, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < 99)
	{
		y = x + 1;
		while (y < 100)
		{
			ft_print(x);
			write(1, " ", 1);
			ft_print(y);
			if (x != 98)
				write(1, ", ", 2);
			y++;
		}
		x++;
	}
}
