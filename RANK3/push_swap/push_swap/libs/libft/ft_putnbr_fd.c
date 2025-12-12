/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:08:59 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/17 00:09:15 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_zero_or_min(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	number[11];
	char	c;
	int		i;

	i = 0;
	ft_zero_or_min(n, fd);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	while (n >= 1)
	{
		c = n % 10 + '0';
		number[i] = c;
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		ft_putchar_fd(number[i - 1], fd);
		i--;
	}
}
