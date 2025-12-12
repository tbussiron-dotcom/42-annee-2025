/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:22:35 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/25 16:04:56 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int	i;

	i = 0;
	dup = malloc(ft_strlen(src) * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stur;
	int			i;

	i = 0;
	stur = malloc((ac + 1) * sizeof(t_stock_str));
	if (!stur)
		return (NULL);
	while (i < ac)
	{
		stur[i].size = ft_strlen(av[i]);
		stur[i].str = av[i];
		stur[i].copy = ft_strdup(av[i]);
		i++;
	}
	stur[i].size = 0;
	stur[i].str = 0;
	stur[i].copy = 0;
	return (stur);
}

int	main(int ac, char **av)
{
	ft_show_tab(ft_strs_to_tab(ac, av));
}
