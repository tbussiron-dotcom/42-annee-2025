/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljouault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:47:17 by ljouault          #+#    #+#             */
/*   Updated: 2025/08/26 11:47:20 by ljouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	first_line_is_valid(char *str)
{
	if (str[0] < '0' || str[0] > '9'
		|| str[1] == str[2]
		|| str[1] == str[3]
		|| str[2] == str[3]
		|| str[1] < ' ' || str[1] > '~'
		|| str[2] < ' ' || str[2] > '~'
		|| str[3] < ' ' || str[3] > '~')
		return (0);
	return (1);
}

int	count_lines(char *str)
{
	int	str_len;
	int	nb_lines;
	int	i;

	str_len = ft_strlen(str);
	if (str[str_len - 1] != '\n')
		return (0);
	nb_lines = 0;
	i = 5;
	while (i < str_len)
	{
		if (str[i] == '\n')
			nb_lines++;
		i++;
	}
	return (nb_lines);
}

int	lines_length_are_equal(char *str)
{
	int	line1;
	int	line2;
	int	start1;
	int	start2;

	line1 = 0;
	start1 = 5;
	while (line1 < str[0] - '0')
	{
		line2 = line1 + 1;
		start2 = start1 + line_length(str, start1) + 1;
		while (line2 < str[0] - '0')
		{
			if (line_length(str, start1) != line_length(str, start2))
				return (0);
			line2++;
			start2 += line_length(str, start2) + 1;
		}
		line1++;
		start1 += line_length(str, start1) + 1;
	}
	return (1);
}

int	line_is_valid(char *str, int start, int length)
{
	int	i;

	if (str[start + length] != '\n')
		return (0);
	i = start;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != str[1]
			&& str[i] != str[2]
			&& str[i] != str[3])
			return (0);
		i++;
	}
	return (1);
}

int	map_is_valid(char *str)
{
	int	line;
	int	start;
	int	length;
	int	height;

	if (!first_line_is_valid(str))
		return (0);
	height = count_lines(str);
	if (height != str[0] - '0' || height < 1)
		return (0);
	if (!lines_length_are_equal(str))
		return (0);
	length = line_length(str, 5);
	if (length < 1)
		return (0);
	line = 0;
	start = 5;
	while (line < height)
	{
		if (!line_is_valid(str, start, length))
			return (0);
		line++;
		start += length + 1;
	}
	return (1);
}
