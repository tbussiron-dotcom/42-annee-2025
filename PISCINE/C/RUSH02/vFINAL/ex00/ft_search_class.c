/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_class.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkloutz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:41:00 by stkloutz          #+#    #+#             */
/*   Updated: 2025/08/24 20:47:48 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rush02.h"

char	*ft_strstr_free(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (to_find[len])
		len++;
	while (str[i])
	{
		if (to_find[j] == str[i])
			j++;
		else if (to_find[j] == '\0' && (str[i] == ' ' || str[i] == ':'))
			break ;
		else
			j = 0;
		i++;
	}
	free(to_find);
	return (&str[i - len]);
}

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
	return (ft_strstr_free(str, class));
}
