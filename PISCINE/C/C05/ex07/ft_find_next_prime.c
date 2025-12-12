/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:50:50 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/14 16:47:32 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	while (i <= nb / 2 && nb % i != 0)
	{
		if ((i - 1) % 3 == 0)
			i = i + 4;
		else
			i = i + 2;
	}
	if (nb % i == 0)
		return (0);
	else
		return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	if (nb == 3)
		return (3);
	if (nb % 2 == 0)
		nb = nb + 1;
	if (nb % 3 == 0)
		nb = nb + 2;
	while (ft_is_prime(nb) == 0)
	{
		if ((nb - 1) % 3 == 0)
			nb = nb + 4;
		else
			nb = nb + 2;
	}
	return (nb);
}
