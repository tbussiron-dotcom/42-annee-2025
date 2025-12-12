/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:46:10 by kbakal            #+#    #+#             */
/*   Updated: 2025/08/09 19:23:37 by kbakal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	error_check1(int x, int y)
{
	if (x < 1)
		write(1, "error, x must be greater than 0", 31);
	if (y < 1)
		write(1, "error, y must be greater than 0", 31);
}

void	rush1(int x, int y)
{
	int	i;
	int	j;

	error_check1(x, y);
	j = 1;
	while (j <= y && x > 0 && y > 0)
	{
		i = 1;
		while (i <= x)
		{
			if ((i == 1 && j == 1))
				ft_putchar('/');
			else if ((i == 1 && j == y) || (i == x && j == 1))
				ft_putchar('\\');
			else if ((i == x && j == y))
				ft_putchar('/');
			else if (i == 1 || i == x || j == 1 || j == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
