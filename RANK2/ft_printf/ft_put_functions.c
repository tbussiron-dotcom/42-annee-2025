/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:14:05 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/19 13:14:07 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

int	ft_puthex(size_t n, char digits[16])
{
	int	nbchar;
	
	printf("%u\\ ", n);
	nbchar = 0;
	if (n > 15)
		nbchar += ft_puthex(n / 16, digits);
	nbchar += ft_putchar(digits[n % 16]);
	return (nbchar);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		nbchar;

	nbchar = 0;
	nb = n;
	if (nb < 0)
	{
		nbchar += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		nbchar += ft_putnbr(nb / 10);
	nbchar += ft_putchar((nb % 10) + '0');
	return (nbchar);
}

int	ft_putunbr(unsigned int n)
{
	int		nbchar;

	nbchar = 0;
	if (n >= 10)
		nbchar += ft_putunbr(n / 10);
	nbchar += ft_putchar((n % 10) + '0');
	return (nbchar);
}

int	ft_putptr(void *p)
{
	int	nbchar;

	nbchar = 0;
	if (!p)
	{
		nbchar += ft_putstr("(nil)");
		return (5);
	}
	nbchar += ft_putstr("0x");
	nbchar += ft_puthex((size_t)p, "0123456789abcdef");
	return (nbchar);
}

#include <stdio.h>

int	main()
{
	printf("\n%p\n", -2147483648);
	ft_printf("\n%p\n", -2147483648);
	
}
