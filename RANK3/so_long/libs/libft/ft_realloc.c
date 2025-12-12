/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:31:20 by thbussir          #+#    #+#             */
/*   Updated: 2025/10/17 18:31:24 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static char	*ft_realloc(char *str, int size)
{
	char	*newstr;
	int	lenstr;

	if (!str)
	{
		newstr = (char *)malloc((size + 1) * sizeof(char));
		newstr[0] = '\0';
		return (newstr);
	}
	lenstr = ft_strlen(str);
	if (lenstr > size)
		lenstr = size;
	newstr = (char *)malloc((size + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, str, lenstr);
	newstr[lenstr] = '\0';
	free(str);
	return (newstr);
}


