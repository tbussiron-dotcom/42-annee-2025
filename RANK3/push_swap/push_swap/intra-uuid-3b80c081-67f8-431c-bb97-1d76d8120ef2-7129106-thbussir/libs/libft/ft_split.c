/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:43:41 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/15 11:43:43 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_countwords(char const *s, char c)
{
	int	words;
	int	i;
	int	inword;

	words = 0;
	i = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != c && inword == 0)
		{
			inword = 1;
			words++;
		}
		else if (s[i] == c)
			inword = 0;
		i++;
	}
	return (words);
}

static int	ft_fill_split(char **strs, char const *s, char c, int nbwords)
{
	int		i;
	int		j;
	size_t	wordlen;

	i = 0;
	j = 0;
	while (s[i] && j < nbwords)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			wordlen = ft_wordlen(s, c, i);
			strs[j] = ft_substr(s, i, wordlen);
			if (!strs[j])
			{
				ft_free_all(strs);
				return (0);
			}
			i += wordlen;
			j++;
		}
	}
	strs[nbwords] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		nbwords;

	if (!s)
		return (NULL);
	nbwords = ft_countwords(s, c);
	strs = (char **)ft_calloc((nbwords + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	if (!ft_fill_split(strs, s, c, nbwords))
		return (NULL);
	return (strs);
}
