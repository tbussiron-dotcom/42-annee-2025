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

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	free_strs(char **str, int len)
{
	while (len >= 0)
	{
		free(str[len]);
		len--;
	}
	free(str);
}

static int	len_file(char *file_name)
{
	int	len;
	int	eof;
	int	fd;
	char	buf[1];
	
        fd = open(file_name, O_RDONLY);
	eof = 1;
	len = 0;
	while (eof != 0)
	{
		eof = read(fd, buf, 1);
		len++;
	}
	close(fd);
	return (len);
}

char	*read_file(char *file_name)
{
	int	fd;
	char	*str;
	int	len;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ("map error\n");
	len = len_file(file_name);
	str = malloc((len + 1) * sizeof(char));
	read(fd, str, len);
	str[len] = '\0';
	close (fd);
	return (str);
}
