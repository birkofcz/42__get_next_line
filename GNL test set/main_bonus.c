/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:32:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/02 10:33:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <fcntl.h> //for open function
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    int fd1 = open("file1.txt", O_RDONLY);

    int i = 0;
    while (i < 8)
    {
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd1));
        i++;
    }
    return (0);
}
