/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkloutz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:41:00 by stkloutz          #+#    #+#             */
/*   Updated: 2025/08/24 17:28:57 by stkloutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);

void	ft_search_tens(char *to_find, char c, char c_next)
{
	if (c == '1')
	{
		to_find[0] = c;
		to_find[1] = c_next;
		to_find[2] = '\0';
	}
	else
	{
		to_find[0] = c;
		to_find[1] = '0';
		to_find[2] = '\0';
	}
	return ;
}

char	*ft_search(int len, char c, char c_next, char *strs)
{
	char	to_find[3];

	if (len % 3 == 2 || len % 3 == 0)
	{
		to_find[0] = c;
		to_find[1] = '\0';
		to_find[2] = '\0';
	}
	else if (len % 3 == 1)
		ft_search_tens(to_find, c, c_next);
	return (ft_strstr(strs, to_find));
}
