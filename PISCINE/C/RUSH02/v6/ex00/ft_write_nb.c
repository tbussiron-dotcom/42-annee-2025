/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:51:29 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/24 21:00:11 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

	void	increment(int *i, int *len);
char	*ft_search_class(int len, int pos, char *str);
void	ft_print(char *str);
int		ft_strlen(char *str);
char	*ft_search(int len, char c, char c_next, char *strs);
char	*ft_strstr(char *str, char *to_find);

void	compact(int len, char *nbr, char *strs, int *i)
{
	ft_print(ft_search(len, nbr[*i], nbr[*i + 1], strs));
	if (nbr[*i] == '1')
		*i = *i + 1;
	if (nbr[*i] != '0')
		write(1, " ", 1);
}

void	ft_write_hundred(char *nbr, char *strs)
{
	int	i;
	int	len;

	len = ft_strlen(nbr) - 1;
	i = 0;
	while (nbr[i])
	{
		if (len % 3 == 1 && nbr[i] != '0')
			compact(len, nbr, strs, &i);
		else if (nbr[i] != '0')
		{
			if (nbr[i] != '0')
			{
				ft_print(ft_search(len, nbr[i], nbr[i + 1], strs));
				if (len % 3 == 2)
				{
					write(1, " ", 1);
					ft_print(ft_strstr(strs, "100"));
				}
			}
			if (nbr[i + 1] && nbr[i + 1] != '0')
				write(1, " ", 1);
		}
		increment(&i, &len);
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
	hundred[j] = '\0';
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

void	ft_write_nb(char *nbr, char *strs)
{
	char	hundred[4];
	char	*nb;
	int		len;
	int		i;

	len = (ft_strlen(nbr) - 1) / 3;
	nb = malloc((len * 3 + 3) * sizeof(char));
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
			ft_print(ft_search_class(len, i, strs));
			write(1, " ", 1);
		}
		i++;
	}
}
