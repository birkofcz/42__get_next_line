/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:30:35 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/02 10:34:05 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h> //for open function
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);

    int i = 0;
    while (i < 8)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
    return (0);
}
