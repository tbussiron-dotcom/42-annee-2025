/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:41:53 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/24 15:05:54 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_search_class(int len, int pos, char *str);
int	ft_strlen(char *str);

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

int	ft_trim(char *str)
{
	int	i;

	i = 0;
	while ((str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a') || (str[i] > 'z'))
		i++;
	return (i);
}

int	ft_strlen_nbr(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

void	ft_print(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = ft_trim(str);
	k = 0;
	j = ft_strlen_nbr(str, i);
	dest = malloc(sizeof(char) * (j + 1));
	while (str[i] != '\0' && str[i] != '\n')
	{
		dest[k] = str[i];
		i++;
		k++;
	}
	dest[j] = '\0';
	ft_putstr(dest);
	free(dest);
}

int	main(int ac, char **av)
{
	(void)ac;
	int 	i;
	int	len;
	char strs[] = "100  : hundred\n1000000: million\n1000000000000000000000000000000000000:     undecillion\n1000000000: billion\n1000000000000: trillion\n1000000000000000: quadrillion\n1000000000000000000   :   quintillion\n1000000000000000000000: sextillion\n1000000000000000000000000: septillion\n1000000000000000000000000000   : octillion\n1000000000000000000000000000000: nonillion\n1000000000000000000000000000000000 : decillion\n1000 : thousand\n";
	len = (ft_strlen(av[1]) - 1) / 3;
	i = 1;
	ft_print(ft_search_class(len, i, strs));
}
