/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:30 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/07 16:38:37 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	while (j < size * 10)
	{	
		if (tab[i] > tab [i + 1])
		{
			t = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = t;
		}
		if (i + 1 == size)
			i = -1;
		i++;
		j++;
	}
}

int	main()
{
	int	size = 10;
	int	tab[] = {5,2,-3,454,9,8,9,8,9,1000000};

	ft_rev_int_tab(tab, size);
	
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	printf("%d\n", tab[4]);
	printf("%d\n", tab[5]);
	printf("%d\n", tab[6]);
	printf("%d\n", tab[7]);
	printf("%d\n", tab[8]);
	printf("%d\n", tab[9]);
}
