/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljouault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:42:51 by ljouault          #+#    #+#             */
/*   Updated: 2025/08/26 09:55:23 by ljouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putstr(char *str);
void	free_strs(char **str, int len);
char	*read_file(char *file_name);
int		ft_strlen(char *str);
int		line_length(char *str, int start);
int		map_is_valid(char *str);
int		ft_atoi(char *str, int length);

typedef struct s_map
{
	char	**lines;
	char	empty;
	char	obstacle;
	char	occupied;
	int		height;
	int		length;
}	t_map;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

#endif
