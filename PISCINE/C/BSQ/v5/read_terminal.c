/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:43:02 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/27 12:43:38 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	dest[i] = src[0];
	dest[i + 1] = '\0';
	return (dest);
}

char	*read_term(void)
{
	char	buf[1];
	char	*str;
	int		fd;	
	int		len;
	int		eof;

	fd = 0;
	eof = 1;
	str = (char *)malloc((4096 + 1) * sizeof(char));
	str[0] = '\0';
	while (eof != 0)
	{
		eof = read(fd, buf, 1);
		if (eof != 0)
			str = ft_strcat(str, buf);
	}
	return (str);
}
