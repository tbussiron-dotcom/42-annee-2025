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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (to_find[len])
		len++;
	if (to_find[0] == '\0')
		return (&str[0]);
	while (str[i])
	{
		if (to_find[j] == str[i])
			j++;
		else if (to_find[j] == '\0')
			break ;
		else 
			j = 0;
		i++;
	}
	if (str[i] == '\0' && to_find[j] != '\0')
		return (0);
	return (&str[i - len]);
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
	class = malloc((len * 3 - pos + 3) * sizeof(char));
	if (!class)
		return (NULL);
	class[0] = '1';
	while (i <= len * 3 - pos)
	{
		class[i] = '0';
		i++;
	}
	j = 0;
	class[i + 1] = '\0';
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
