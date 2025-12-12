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

int	ft_strlen(char *str)
{
	int	i;

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

int	ft_strstr(char *str, char *to_find)
{
	int				i;
	unsigned int	len_to_find;

	i = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return (0);
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

char	*ft_search_class(int len, int pos, char **strs)
{
	int	i;
	int	j;
	char	*class;
	
	if (pos == len)
		return (NULL);
	i = 1;
	pos = pos * 3;
	class = malloc((len * 3 - pos + 2) * sizeof(char));
	if (!class)
		return (NULL);
	class[0] = '1';
	while (i <= len * 3 - pos)
	{
		class[i] = '0';
		i++;
	}
	j = 0;
	while (strs[j])
	{
		class[i] = ' ';
		if (ft_strstr(strs[j], class))
		{
			free(class);
			return (strs[j]);
		}
		class[i] = ':';
		if (ft_strstr(strs[j], class))
		{
			free(class);
			return (strs[j]);
		}
		j++;
	}
	free(class);
	return (NULL);
}

int	main(int ac, char **av)
{
	(void)ac;
	int 	i;
	int	len;
	char *strs[50] = {"100: hundred", 
	"1000 : thousand", 
	"1000000: million",
	"1000000000000000000000000000000000000: undecillion",
	"1000000000: billion", 
	"1000000000000: trillion", 
	"1000000000000000: quadrillion", 
	"1000000000000000000: quintillion", 
	"1000000000000000000000: sextillion", 
	"1000000000000000000000000: septillion", 
	"1000000000000000000000000000: octillion", 
	"1000000000000000000000000000000: nonillion", 
	"1000000000000000000000000000000000 : decillion"};

	len = (ft_strlen(av[1]) - 1) / 3;
	i = 0;
	printf("%s", ft_search_class(len, i, strs));
}
