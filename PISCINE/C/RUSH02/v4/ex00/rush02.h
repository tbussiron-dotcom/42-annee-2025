/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:07:49 by jmuth             #+#    #+#             */
/*   Updated: 2025/08/24 15:06:25 by jmuth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

int		ft_strlen(char *str);
void	ft_write_nb(char *str);
void	free_arr(char **strs, int i);
void	ft_write_error(int err);
int		ft_check_nb(char *str);
void	ft_putstr(char *str);
void	ft_print(char *str);
int		ft_strlen_alpha(char *str);
int		ft_trim(char *str);

#endif
