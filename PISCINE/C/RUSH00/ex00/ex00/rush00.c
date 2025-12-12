/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:15:37 by kbakal            #+#    #+#             */
/*   Updated: 2025/08/09 19:20:40 by kbakal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	error_check0(int x, int y)
{
	if (x < 1)
		write(1, "error, x must be greater than 0", 31);
	if (y < 1)
		write(1, "error, y must be greater than 0", 31);
}

void	rush0(int x, int y)
{
	int	i;
	int	j;

	error_check0(x, y);
	j = 1;
	while (j <= y && y > 0 && x > 0)
	{
		i = 1;
		while (i <= x)
		{
			if ((j == 1 && i == 1) || (j == y && i == 1))
				ft_putchar('o');
			else if ((i == x && j == y) || (i == x && j == 1))
				ft_putchar('o');
			else if (i == 1 || i == x)
				ft_putchar('|');
			else if (j == 1 || j == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
