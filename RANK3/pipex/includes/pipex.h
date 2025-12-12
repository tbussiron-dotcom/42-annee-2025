/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:37:46 by thbussir          #+#    #+#             */
/*   Updated: 2025/11/11 18:37:48 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*============================================================================*/

int				ft_printf(char	*format, ...);
int				ft_isdigit(int c);
void			*ft_calloc(size_t nmemb, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *dest, char *src);
char			*ft_strchr(char *str, char c);
size_t			ft_strlen(const char	*str);
long long int	ft_atoi(const char *nptr);

/*============================================================================*/
#endif
