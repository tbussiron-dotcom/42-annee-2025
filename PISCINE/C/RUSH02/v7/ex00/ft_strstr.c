/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:54:30 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/24 19:55:09 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	return (&str[i - len]);
}
