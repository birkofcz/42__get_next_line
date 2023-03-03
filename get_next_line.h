/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:33:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/02/24 18:27:19 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //write and read defs
# include <stdlib.h> // malloc, free
# include <stddef.h> // for ssize_t definition

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

int		ft_test(char *pool);
char	*ft_line(char *pool);
char	*ft_newpool(char *pool);
char	*get_next_line(int fd);

/* Utility functions */
size_t	ft_strlen(const char *s);
char	*ft_write_pool(char *pool, char *buffer);
char	*ft_strjoin(char *pool, char *buffer);

#endif
