/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:52:24 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/12 17:40:07 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	checks(char *base, long long int *n)
{
	if (base_check(base) == 0)
		return ;
	if (*n == 0)
		write(1, "0", 1);
	if (*n < 0)
	{
		write(1, "-", 1);
		*n = *n * -1;
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	char			nbr[32];
	long long int	i;
	long long int	len;
	long long int	n;

	n = (long long int)nb;
	len = ft_strlen(base);
	checks(base, &n);
	i = 0;
	while (n != 0)
	{
		nbr[i] = base[n % len];
		n = n / len;
		i++;
	}
	nbr[i] = nbr[n % len];
	while (i >= 0)
	{
		write(1, &nbr[i - 1], 1);
		i--;
	}
}
