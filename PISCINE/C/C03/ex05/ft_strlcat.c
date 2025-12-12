/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:46:31 by thbussir          #+#    #+#             */
/*   Updated: 2025/08/11 14:57:19 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
        unsigned int    i;
        unsigned int    j;
        unsigned int    len;

        i = 0;
        j = 0;
        while (dest[i] != '\0')
                i++;
        len = i;

        if (src[0] == '\0')
                return (len);
        while (src[j] != '\0' && j < size)
        {
                dest[i] = src[j];
                i++;
                j++;
        }
        dest[i] = '\0';
        return ();
}

