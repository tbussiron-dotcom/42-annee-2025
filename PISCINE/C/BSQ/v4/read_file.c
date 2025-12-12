/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:17:16 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/26 16:09:05 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_strs(char **str, int len)
{
	while (len >= 0)
	{
		free(str[len]);
		len--;
	}
	free(str);
}

int	len_file(char *file_name)
{
	char	buf[1];
	int		len;
	int		eof;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	eof = 1;
	len = 0;
	while (eof != 0)
	{
		eof = read(fd, buf, 1);
		if (eof == -1)
			return (0);
		len++;
	}
	close(fd);
	return (len);
}

char	*read_file(char *file_name)
{
	char	*str;
	int		fd;	
	int		len;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	len = len_file(file_name);
	str = (char *)malloc((len + 1) * sizeof(char));
	read(fd, str, len);
	str[len - 1] = '\0';
	close (fd);
	return (str);
}
