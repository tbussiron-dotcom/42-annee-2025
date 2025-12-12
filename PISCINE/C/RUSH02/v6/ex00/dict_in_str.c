/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_in_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:23:31 by pchazalm          #+#    #+#             */
/*   Updated: 2025/08/24 20:03:44 by stkloutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*dict_in_str(char **strs)
{
	int		fd_fill;
	int		fd_count;
	int		count;
	char	buf[1];
	int		eof;

	eof = 1;
	count = 0;
	fd_fill = open("numbers.dict", O_RDONLY);
	fd_count = open("numbers.dict", O_RDONLY);
	while (eof != 0)
	{
		eof = read(fd_count, buf, 1);
		count++;
	}
	*strs = malloc(sizeof(char) * (count + 1));
	read(fd_fill, *strs, count);
	(*strs)[count] = '\0';
	return (*strs);
}
