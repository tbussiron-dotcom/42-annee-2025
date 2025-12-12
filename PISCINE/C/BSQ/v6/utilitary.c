/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljouault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:54:15 by ljouault          #+#    #+#             */
/*   Updated: 2025/08/26 11:57:44 by ljouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

int	ft_atoi(char *str, int length)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < length - 3
		&& '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	line_length(char *str, int start)
{
	int	str_len;
	int	length;

	str_len = ft_strlen(str);
	length = 0;
	while (start + length < str_len && str[start + length] != '\n')
		length++;
	return (length);
}
