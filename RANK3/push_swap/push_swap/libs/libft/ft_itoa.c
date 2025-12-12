/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:42:44 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/15 15:42:48 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_imintoa(int n)
{
	char	*str;
	int		i;

	i = 9;
	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	str[11] = '\0';
	str[10] = '8';
	str[9] = '4';
	str[8] = '6';
	str[7] = '3';
	str[6] = '8';
	str[5] = '4';
	str[4] = '7';
	str[3] = '4';
	str[2] = '1';
	str[1] = '2';
	str[0] = '-';
	return (str);
}

static char	*ft_nitoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
	{
		str = ft_imintoa(n);
		return (str);
	}
	n = -n;
	i = ft_nblen(n);
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	while (i > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n < 0)
	{
		str = ft_nitoa(n);
		return (str);
	}
	i = ft_nblen(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
