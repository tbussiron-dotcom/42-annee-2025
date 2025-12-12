/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:22:43 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/18 16:05:15 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int	*range;
	
	if (min >= max)
		return (NULL);
	range = (int *) malloc((max - min + 1) * sizeof(int));
	i = 0;
	while (min < max)
	{
		range[i] = min;
		i++;
		min++; 
	}
	return(range);
}
