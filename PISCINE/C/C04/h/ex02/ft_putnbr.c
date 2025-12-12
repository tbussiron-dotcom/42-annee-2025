/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:57:53 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/05 18:58:12 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_zero_or_min(int nb)
{
	if (nb == 0)
	{
		write (1, "0", 1);
	}
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
}

void	ft_putnbr(int nb)
{
	char	number[11];
	char	c;
	int		i;

	i = 0;
	ft_zero_or_min(nb);
	if (nb < 0 && nb != -2147483648)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	while (nb >= 1)
	{
		c = nb % 10 + '0';
		number[i] = c;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &number[i - 1], 1);
		i--;
	}
}
