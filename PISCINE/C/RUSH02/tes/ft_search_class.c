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

int	ft_strlen(char *str);

char	*ft_strstr(char *str, char *to_find)

char	*ft_search_class(int len, int pos, char *str)
{
	int		i;
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
	class[i] = '\0';
	return (ft_strstr(str, class));
}

/*int	main(int ac, char **av)
{
	(void)ac;
	int 	i;
	int	len;
	char strs[] = "100  : hundred\n1000000: million\n1000000000000000000000000000000000000:     undecillion\n1000000000: billion\n1000000000000: trillion\n1000000000000000: quadrillion\n1000000000000000000   :   quintillion\n1000000000000000000000: sextillion\n1000000000000000000000000: septillion\n1000000000000000000000000000   : octillion\n1000000000000000000000000000000: nonillion\n1000000000000000000000000000000000 : decillion\n1000 : thousand\n";
	len = (ft_strlen(av[1]) - 1) / 3;
	i = 0;
	printf("%s", ft_search_class(len, i, strs));
}*/
