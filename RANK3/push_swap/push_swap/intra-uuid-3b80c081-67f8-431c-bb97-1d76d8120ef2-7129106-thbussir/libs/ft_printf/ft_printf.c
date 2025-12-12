/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:05:34 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/18 14:05:43 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_print_type(const char *format, int *i, va_list *params)
{
	int	nbchar;

	(*i)++;
	nbchar = 0;
	if (format[*i] == 'c')
		nbchar = ft_putchar(va_arg(*params, int));
	else if (format[*i] == 's')
		nbchar = ft_putstr(va_arg(*params, char *));
	else if (format[*i] == 'p')
		nbchar = ft_putptr((va_arg(*params, void *)));
	else if (format[*i] == 'd')
		nbchar = ft_putnbr(va_arg(*params, int));
	else if (format[*i] == 'i')
		nbchar = ft_putnbr(va_arg(*params, int));
	else if (format[*i] == 'u')
		nbchar = ft_putunbr(va_arg(*params, unsigned int));
	else if (format[*i] == 'x')
		nbchar = ft_puthex(va_arg(*params, unsigned int), "0123456789abcdef");
	else if (format[*i] == 'X')
		nbchar = ft_puthex(va_arg(*params, unsigned int), "0123456789ABCDEF");
	else if (format[*i] == '%')
		nbchar = ft_putchar('%');
	else
		nbchar = ft_putchar('%') + ft_putchar(format[*i]);
	return (nbchar);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		nbchar;

	nbchar = 0;
	if (!format)
		return (-1);
	va_start(params, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%')
			nbchar += ft_print_type(format, &i, &params);
		else
			nbchar += ft_putchar(format[i]);
		i++;
	}
	if (nbchar == -1)
		return (-1);
	va_end(params);
	return (nbchar);
}
