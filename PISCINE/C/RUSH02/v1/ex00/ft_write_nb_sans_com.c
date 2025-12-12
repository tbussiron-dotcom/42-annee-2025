/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nb_steph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:51:29 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/23 17:49:24 by stkloutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_write_hundred(char *nbr, char **strs)
{
	int	i;
	int	len;

	len = ft_strlen(nbr) - 1;
	i = 0;
	while (nbr[i])
	{
		if (len % 3 == 1)
		{
			if (nbr[i] == '1')
			{
				ft_putstr(strs[nbr[i] - '0' + 9 + nbr[i + 1] - '0']);
				i += 2;
			}
			else if (nbr[i] != '0')
			{
				ft_putstr(strs[nbr[i] - '0' + 18]);
				i++;
				if (nbr[i] != '0')
					write(1, " ", 1);
			}
		}
		else
		{
			if (nbr[i] != '0')
			{
				ft_putstr(strs[nbr[i] - '0']);
				if (len % 3 == 2)
				{
					write(1, " ", 1);
					ft_putstr(strs[28]);
				}
			}
			if (nbr[i + 1] && nbr[i + 1] != '0')
				write(1, " ", 1);
			i++;
		}
		len--;
	}
}

char	*take_hundred(char *hundred, char *nbr, int pos)
{
	int	i;
	int	j;

	i = pos * 3;
	j = 0;
	while (i < pos * 3 + 3)
	{
		hundred[j] = nbr[i];
		i++;
		j++;
	}
	return (hundred);
}

char	*fill_nb(char *nb, char *nbr)
{
	int	i;
	int	j;
	int	len;
	
	i = 0;
	j = 0;
	len = ft_strlen(nbr) % 3;
	while (i < 3 - len && len != 0)
	{
		nb[i] = '0';
		i++;
	}
	while (nbr[j])
	{
		nb[i] = nbr[j];
		i++;
		j++;
	}
	nb[i] = '\0';
	return (nb);
}

void	ft_write_nb(char *nbr, char **strs)
{
	char	hundred[4];
	char	*nb;
	int	len;
	int	i;

	len = (ft_strlen(nbr) - 1) / 3;
	nb = malloc((len * 3 + 3)* sizeof(char));
	if (!nb)
		return ;
	fill_nb(nb, nbr);
	i = 0;
	while (i <= len)
	{
		ft_write_hundred(take_hundred(hundred, nb, i), strs);
		if (i != len)
		{
			write(1, " ", 1);
			ft_putstr(strs[28 + len - i]);
			write(1, " ", 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	char *strs[50] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion"};
	ft_write_nb(av[1], strs);
}
	




