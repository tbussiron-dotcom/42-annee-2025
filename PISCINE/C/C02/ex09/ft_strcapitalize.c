/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:14:43 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/08 20:12:00 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcapitalize(char *src)
{
	int	i;
	int	b;

	b = 1;
	i = 0;
	while (src[i] != '\0')
	{
		if ((src[i] < 'A' || src[i] > 'Z')
			&& (src[i] < 'a' || src[i] > 'z')
			&& (src[i] < '0' || src[i] > '9'))
			b = 1;
		if ((src[i] >= 'A' && src[i] <= 'Z') && b == 0)
			src[i] += 32;
		if ((src[i] >= 'a' && src[i] <= 'z') && b == 1)
			src[i] -= 32;
		if ((src[i] >= 'A' && src[i] <= 'Z')
			|| (src[i] >= 'a' && src[i] <= 'z')
			|| (src[i] >= '0' && src[i] <= '9'))
			b = 0;
		i++;
	}
	return (src);
}
