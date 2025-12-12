/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:22:09 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/19 14:22:11 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (strs[i])
		len += ft_strlen(strs[i++]);
	len = len + ft_strlen(sep) * (size - 1);
	if (size == 0)
		len = 0;
	str = malloc(len * sizeof(char));
	if (size == 0)
		return (str);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i], sep, i);
		if (i + 1 < size)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
