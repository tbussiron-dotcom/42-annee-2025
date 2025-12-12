/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkloutz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:41:00 by stkloutz          #+#    #+#             */
/*   Updated: 2025/08/24 14:01:09 by stkloutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_is_strstr(char *str, char *to_find)
{
	int				i;
	unsigned int	len_to_find;

	i = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_strncmp(to_find, str + i, len_to_find) == 0
				&& (str[len_to_find + 1] < '0' || str[len_to_find + 1] > '9')
				&& (str[i - 1] < '0' || str[i - 1] > '9'))
				return (1);
			else
				i++;
		}
		else
			i++;
	}
	return (0);
}

char	*ft_search_tens(char c, char c_next)
{
	char	*to_find[3];

	if (c == 1)
	{
		to_find[0] = c;
		to_find[1] = c_next;
		to_find[2] = '\n';
	}
	else
	{
		to_find[0] = c;
		to_find[1] = '0';
		to_find[2] = '\n';
	}
	return (to_find);
}

int	ft_search(int len, char c, char c_next, char **strs)
{
	int		i;
	int		j;
	char	to_find[3];

	i = 0;
	j = 0;
	if (len % 3 == 2 || len % 3 == 0)
	{
		to_find[0] = c;
		to_find[1] = '\n';
	}
	else if (len % 3 == 1)
		to_find = ft_search_tens();
	while (strs[i])
	{
		while (strs[i][j])
		{
			if (ft_is_strstr(strs[i], to_find))
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
