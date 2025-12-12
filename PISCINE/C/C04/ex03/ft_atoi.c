/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:41:16 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/12 10:41:18 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_neg(int sign)
{
	if (sign % 2 == 0)
		return (1);
	return (-1);
}

int	add_nbr(int i, int nb, int *in_nb, char *str)
{
	*in_nb = 1;
	nb = 10 * nb + str[i] - '0';
	return (nb);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;
	int	in_nb;

	i = 0;
	nb = 0;
	sign = 0;
	in_nb = 0;
	while (str[i])
	{
		if (str[i] == '-' && in_nb == 0)
			sign++;
		if (str[i] >= '0' && str[i] <= '9')
			nb = add_nbr(i, nb, &in_nb, str);
		if ((((str[i] < '0' || str[i] > '9')
					&& ((str[i] != '-' && str[i] != '+' && str[i] != ' '
							&& str[i] < 9 && str[i] > 13)))
				|| ((str[i] == ' ' || str[i] == '-' || str[i] == '+'
						|| (str[i] > 8 && str[i] < 14)) && in_nb == 1)
				|| (str[i] == ' ' && sign > 0)))
			break ;
		i++;
	}
	return (nb * test_neg(sign));
}
