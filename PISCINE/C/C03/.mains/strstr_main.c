/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:50:00 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/11 18:50:11 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int main(int ac, char **av)
{
	(void)ac;
	char *str;
	char *to_find;
	str = strdup(av[1]);
	to_find = strdup(av[2]);

	{
			printf("ft_strstr: %p\n",ft_strstr(str, to_find));
		printf("%s\t%s\n\n", str, to_find);
	}
	{
		to_find = strdup(av[2]);
		printf("ft_strstr: %p\n", strstr(str, to_find));
		printf("%s\t%s\n\n", str, to_find);
	}

	return 0;
}
