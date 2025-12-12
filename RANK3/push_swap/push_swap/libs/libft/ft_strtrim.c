/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:59:56 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/15 10:59:57 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_midstart(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	ismid;

	i = 0;
	j = 0;
	ismid = 0;
	while (s1[i] && ismid == 0)
	{
		ismid = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
				ismid = 0;
			j++;
		}
		if (ismid == 1)
			return (i);
		j = 0;
		i++;
	}
	return (0);
}

static int	ft_midend(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	ismid;

	i = ft_strlen(s1) - 1;
	j = 0;
	ismid = 0;
	while (i >= 0 && ismid == 0)
	{
		ismid = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
				ismid = 0;
			j++;
		}
		if (ismid == 1)
			return (i + 1);
		j = 0;
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_midstart(s1, set);
	end = ft_midend(s1, set);
	i = 0;
	trim = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	while (start < end)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}
