/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:05:59 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/16 17:15:48 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print(char	**av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*t;

	if (ac == 1)
		return (0);
	while (ac > 0)
	{
		i = 1;
		while (av[i + 1])
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				t = av[i];
				av[i] = av[i + 1];
				av[i + 1] = t;
			}
			i++;
		}
		ac--;
	}
	ft_print(av);
	return (0);
}
