/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:19:12 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/21 15:19:14 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*find_nl(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (temp + i);
		i++;
	}
	return (NULL);
}

static char	*fill_line(char *temp)
{
	int		i;
	char	*line;

	if (!temp || !temp[0])
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] && temp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*trim_temp(char *temp)
{
	char	*newline;
	char	*new_temp;

	if (!temp)
		return (NULL);
	newline = find_nl(temp);
	if (!newline)
	{
		free(temp);
		return (NULL);
	}
	new_temp = ft_strdup(newline + 1);
	free(temp);
	return (new_temp);
}

char	*return_line(char **temp, char *buf)
{
	char	*line;

	free(buf);
	if (!*temp || !(*temp)[0])
	{
		if (*temp)
			free(*temp);
		*temp = NULL;
		return (NULL);
	}
	line = fill_line(*temp);
	*temp = trim_temp(*temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*temp = NULL;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!find_nl(temp) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		if (bytes > 0)
			temp = ft_strjoin(temp, buf);
	}
	line = return_line(&temp, buf);
	return (line);
}
