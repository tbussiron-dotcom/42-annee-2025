/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:41:53 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/24 21:11:14 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

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
	if (!dest)
		return ;
	if (str == NULL)
		return ;
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
