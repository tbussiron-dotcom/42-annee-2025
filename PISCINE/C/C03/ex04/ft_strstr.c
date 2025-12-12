/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:39:53 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/12 10:30:18 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (to_find[len])
		len++;
	if (to_find[0] == '\0')
		return (&str[0]);
	while (str[i])
	{
		if (to_find[j] == str[i])
			j++;
		else if (to_find[j] == '\0')
			break ;
		else 
			j = 0;
		i++;
	}
	if (str[i] == '\0' && to_find[j] != '\0')
		return (0);
	return (&str[i - len]);
}
