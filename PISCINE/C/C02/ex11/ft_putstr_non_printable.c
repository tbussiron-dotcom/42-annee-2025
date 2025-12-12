/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:11:15 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/11 16:47:14 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] < 0)
		{
			write(1, "\\", 1);
			write(1, &hexa[(256 + str[i]) / 16], 1);
			write(1, &hexa[(256 + str[i]) % 16], 1);
		}
		if ((str[i] >= 0 && str[i] < 32) || str[i] > 126)
		{
			write(1, "\\", 1);
			write(1, &hexa[str[i] / 16], 1);
			write(1, &hexa[str[i] % 16], 1);
		}
		else if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		i++;
	}
}

int	main()
{
	char	caca[256];
	
	for(int i = 1; i <= 255; i++)
	{
		caca[i-1] = i;
	}
	
	ft_putstr_non_printable(caca);
	return (0);
}
