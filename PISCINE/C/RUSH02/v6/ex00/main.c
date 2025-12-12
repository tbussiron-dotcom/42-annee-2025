/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:35:44 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/24 15:56:43 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_write_nb(char *nbr, char *strs);
char	*dict_in_str(char **strs);

int	main(int ac, char **av)
{
	char	*strs;

	if (ac == 2)
	{
		strs = dict_in_str(&strs);
		ft_write_nb(av[1], strs);
	}
	return (0);
}
