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

static int	first_line_is_valid(char *str)
{
	int	first_line_length;
	int	i;

	first_line_length = line_length(str, 0);
	if (first_line_length < 4)
		return (0);
	i = 0;
	while (i < first_line_length - 3)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[i] == str[i + 1]
		|| str[i] == str[i + 2]
		|| str[i + 1] == str[i + 2]
		|| str[i] < ' ' || str[i] > '~'
		|| str[i + 1] < ' ' || str[i + 1] > '~'
		|| str[i + 2] < ' ' || str[i + 2] > '~')
		return (0);
	return (1);
}

static int	count_lines(char *str)
{
	int	str_len;
	int	nb_lines;
	int	i;

	str_len = ft_strlen(str);
	nb_lines = 0;
	i = line_length(str, 0) + 1;
	while (i < str_len)
	{
		if (str[i] == '\n')
			nb_lines++;
		i++;
	}
	return (nb_lines);
}

static int	lines_length_are_equal(char *str, int height)
{
	int	line;
	int	length;
	int	start;

	line = 0;
	length = line_length(str, 0);
	start = length + 1;
	while (line < height - 1)
	{
		length = line_length(str, start);
		if (line_length(str, start) != line_length(str, start + length + 1))
			return (0);
		line++;
		start += line_length(str, start) + 1;
	}
	return (1);
}

static int	lines_are_valid(char *str, int height, int length)
{
	int	first_line_length;
	int	start;
	int	line;
	int	i;

	first_line_length = line_length(str, 0);
	line = 0;
	start = line_length(str, 0) + 1;
	while (line < height)
	{
		i = start;
		while (str[i] && str[i] != '\n')
		{
			if (str[i] != str[first_line_length - 3]
				&& str[i] != str[first_line_length - 2]
				&& str[i] != str[first_line_length - 1])
				return (0);
			i++;
		}
		line++;
		start += length + 1;
	}
	return (1);
}

int	map_is_valid(char *str)
{
	int	length;
	int	height;
	int	first_line_length;

	if (!first_line_is_valid(str))
		return (0);
	height = count_lines(str);
	if (height != ft_atoi(str, line_length(str, 0)) || height < 1)
		return (0);
	if (!lines_length_are_equal(str, height))
		return (0);
	first_line_length = line_length(str, 0);
	length = line_length(str, first_line_length + 1);
	if (length < 1)
		return (0);
	if (!lines_are_valid(str, height, length))
		return (0);
	return (1);
}
