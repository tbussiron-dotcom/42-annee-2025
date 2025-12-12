/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkloutz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:41:00 by stkloutz          #+#    #+#             */
/*   Updated: 2025/08/24 12:02:08 by stkloutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_is_strstr(char *str, char *to_find)
{
	int				i;
	unsigned int	len_to_find;

	i = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return (0); // ou erreur ?
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_strncmp(to_find, str + i, len_to_find) == 0)
				return (1);
			else
				i++;
		}
		else
			i++;
	}
	return (0);
}

int	ft_search_class(int len, int pos, char **strs)
{
	int	i;
	int	j;
	char	*class;
	
	i = 1;
	pos = pos * 3;
	class = malloc((len * 3 - pos + 1) * (char));
	if (!class)
		return (-1);
	class[0] = '1';
	while (i < len * 3 - pos)
	{
		class[i] = 0;
		i++;
	}
	printf("%s", class);
	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			return 0;
		}
		i++;
	}
}

int	ft_search(int len, char c, char c_next, char **strs)
{
	int	i;
	int	j;
	char to_find[3];

	i = 0;
	j = 0;
	//search class if (len % 3 == 0 && len / 3 > 0) -> Thomas
	//search unit
	if (len % 3 == 2 || len % 3 == 0)
	{
		to_find[0] = c;
		to_find[1] = '\n';
	}

	//search tens -> trop long, faire une fonction char *ft_search_tens(modulo, c, c_next)
	else if (len % 3 == 1 )
	{
		if c == 1 // 10 -> 19
		{
			to_find[0] = c;
			to_find[1] = c_next;
			to_find[2] = '\n';
		}
		else //search 20 -> 90
		{
			to_find[0] = c;
			to_find[1] = '0';
			to_find[2] = '\n';
		}
	}
	while (strs[i])
	{
		while (strs[i][j])
		{
			if (ft_is_strstr(strs[i], to_find))
				return (i);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	char *strs[50] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion"};
	len = (ft_strlen(nbr) - 1) / 3;
	i = 0;
	ft_search_class(len, i, strs);
}
