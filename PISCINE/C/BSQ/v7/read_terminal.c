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

char	*ft_strdup(char *src, int size)
{
	int		i;
	char	*dup;
	
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}

char	*ft_realloc(char *str, int size)
{
	char	*temp;
	
	temp = ft_strdup(str, size);
	free(str);
	str = ft_strdup(temp, size);
	free(temp);
	return (str);
}

char	*read_term(void)
{
	char	buf[1];
	char	*str;
	int		fd;
	int		len;
	int		eof;
	int		size;

	fd = 0;
	eof = 1;
	size = 1;
	str = malloc(2 * sizeof(char));
	str[0] = '\0';
	str[1] = '\0';
	while (1)
	{
		eof = read(fd, buf, 1);
		if (eof == 0)
			break ;
		str = ft_realloc(str ,size + 1);	
		str = ft_strcat(str, buf);
		size++;
	}
	ft_putstr("\n");
	ft_putstr(str);
	return (str);
}
