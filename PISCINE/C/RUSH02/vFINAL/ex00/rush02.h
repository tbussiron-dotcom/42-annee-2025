/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:07:49 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/24 21:30:49 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

int		ft_strlen(char *str);
int		ft_check_nb(char *str);
int		ft_check_zero(char *nbr);
void	ft_putstr(char *str);
void	ft_print(char *str);
char	*ft_search(int len, char c, char c_next, char *strs);
char	*ft_search_class(int len, int pos, char *str);
char	*ft_strstr(char *str, char *to_find);
void	ft_write_nb(char *nbr, char *strs);
char	*dict_in_str(char **strs);
void	increment(int *i, int *len);

#endif
