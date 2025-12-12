/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:42:41 by kbakal            #+#    #+#             */
/*   Updated: 2025/08/10 13:57:33 by kbakal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush0(int x, int y);
void	rush1(int x, int y);
void	rush2(int x, int y);
void	rush3(int x, int y);
void	rush4(int x, int y);

void	choose_rush(int x, int y, char rush, char arg_ok)
{
	if (arg_ok == '\0')
	{
		if (rush == '0')
			rush0(x, y);
		if (rush == '1')
			rush1(x, y);
		if (rush == '2')
			rush2(x, y);
		if (rush == '3')
			rush3(x, y);
		if (rush == '4')
			rush4(x, y);
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (argv[1][i] != '\0' && (argc == 3 || argc == 4))
	{
		x = x * 10 + argv[1][i] - '0';
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0' && (argc == 3 || argc == 4))
	{
		y = y * 10 + argv[2][i] - '0';
		i++;
	}
	if (argc == 4)
		choose_rush(x, y, argv[3][0], argv[3][1]);
	else if (argc == 3)
		rush1(x, y);
	return (0);
}
