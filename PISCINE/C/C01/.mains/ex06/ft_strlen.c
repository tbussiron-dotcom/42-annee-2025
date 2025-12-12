/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:59:52 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/07 14:04:32 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;
	
	while(str[i] != '\0')
		i++;
	return(i);
}

int	main()
{
	char *str;	
	str = "je mange du gayo";

	printf("%d\n", ft_strlen(str));
}
