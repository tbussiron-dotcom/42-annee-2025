/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:07:19 by thbussir          #+#    #+#             */
/*   Updated: 2025/12/07 22:31:34 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_tab(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (ft_atoi(s) > 2147483647 || ft_atoi(s) < -2147483648)
		return (0);
	return (1);
}

static int	has_duplicate(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (!is_valid_number(tab[i]))
		{
			free_tab(tab);
			return (0);
		}
		i++;
	}
	if (has_duplicate(tab))
	{
		free_tab(tab);
		return (0);
	}
	return (1);
}

int	parse(int ac, char **av, int **values)
{
	int		size;
	char	**tab;
	char	*av_start;

	*values = NULL;
	av_start = *av;
	while (--ac)
	{
		(*av)[ft_strlen(*av)] = ' ';
		av++;
	}
	tab = ft_split(av_start, ' ');
	if (!check_tab(tab))
		return (0);
	size = 0;
	while (tab[size])
		size++;
	*values = malloc(size * sizeof(int));
	while (*values && tab[ac])
		(*values)[--size] = ft_atoi(tab[ac++]);
	free_tab(tab);
	return (ac);
}
