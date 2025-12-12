/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:12:08 by thbussir          #+#    #+#             */
/*   Updated: 2025/11/08 14:12:10 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int     fd1;
    int     fd2;
    int     fd3;
    char    *file1 = "file1";
    char    *file2 = "file2";
    char    *file3 = "file3";
    char    *line1;
    char    *line2;
    char    *line3;

    fd1 = open(file1, O_RDONLY);
    fd2 = open(file2, O_RDONLY);
    fd3 = open(file3, O_RDONLY);
    do
    {
        line1 = get_next_line(fd1);
        if (!line1)
			break ;
        printf("1 : %s", line1);
        free(line1);
        line2 = get_next_line(fd2);
        if (!line2)
			break ;
        printf("2 : %s", line2);
        free(line2);
        line3 = get_next_line(fd3);
        if (!line3)
			break ;
        printf("3 : %s", line3);
        free(line3);
    } while (1);
    close(fd1);
    close(fd2);
    close(fd3);
}
