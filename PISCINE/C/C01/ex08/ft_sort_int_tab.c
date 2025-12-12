/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:30 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/08 18:03:03 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *tab, int *swaps, int i)
{
	int	t;

	t = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = t;
	*swaps += 1;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swaps;

	swaps = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab [i + 1])
				ft_swap(tab, &swaps, i);
			i++;
		}
		j++;
		if (swaps == 0)
			break ;
		swaps = 0;
	}
}
