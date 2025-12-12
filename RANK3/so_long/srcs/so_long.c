/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:38:32 by thbussir          #+#    #+#             */
/*   Updated: 2025/12/10 19:38:34 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_line(char *line, int (*char_count)[3])
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			(*char_count)[0]++;
		else if (line[i] == 'E')
			(*char_count)[1]++;
		else if (line[i] == 'C')
			(*char_count)[2]++;
		else if (line[i] != '1' && line[i] != '\n')
			return (0);
		i++;
	}
	if (line[i] != '1' && line[i] != '\n')
		return (0);
	return (1);
}

int	check_side(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (0);
	}
	return (1);
}
/*
int	check_map(int fd)
{
	char		*line;
	static int	char_count[3] = {0, 0, 0};
	int			line_len;
	int			last_line;
	int			i;

	i = 0;
	last_line = 1;
	line = get_next_line(fd);
	line_len = ft_strlen(line);
	while (line)
	{
		if (!line[line_len - 1] || line[line_len - 1] != '\n')
		{
			free(line);
			return (0);
		}
		if (!check_line(line, &char_count, i, &last_line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (char_count[0] != 1 && char_count[1] != 1 && char_count[2] < 1)
		return (0);
	if (last_line == 0)
		return (0);
	return (1);
}*/

int	check_map(char **map)
{
	int	i;
	static int	char_count[3] = {0, 0, 0};
	
	i = 1;
	while (map[i] && map[i + 1])
	{
		if (!check_line(map[i], &char_count))
			return (0);
		i++;
	}
	if (!check_side(map[0]) || !check_side(map[i]))
		return (0);
	return (1);
}

int	count_lines(char *file)
{
	int		fd;
	char	*str;
	int		count;
	
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	count = 0;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

void	free_map(char **map)
{
	int	i;
	
	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char **parse(int fd, char *file)
{
	char	**map;
	char	*str;
	int		i;

	map = malloc((count_lines(file) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		map[i] = ft_strdup(str);
		free(str);
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		str = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**map;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	map = parse(fd, av[1]);
	if (!check_map(map))
	{
		free_map(map);
		write(1, "KO", 2);
		return (0);
	}
	free_map(map);
	write(1, "OK", 2);
	close(fd);
	return (1);
}
