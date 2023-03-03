/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:24:00 by sbenes            #+#    #+#             */
/*   Updated: 2023/03/02 16:37:54 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ft_test - to test if there is a '\n' in the pool.
Used to make a while loop in get_next_line for pool writing.
Returns 1 if TRUE and stops the pool writing to start the line 
extraction and pool trimming.
*/

int	ft_test(char *pool)
{
	int	i;

	if (!pool)
		return (0);
	i = 0;
	while (pool[i] != '\n' && pool[i] != '\0')
		i++;
	if (pool[i] == '\n')
		return (1);
	return (0);
}

/*
ft_line - extracts the line from pool (with \n or not), copy 
it to "buffer" and returns it.
*/

char	*ft_line(char *pool)
{
	int		i;
	char	*buffer;

	if (!pool || !pool[0])
		return (NULL);
	i = 0;
	while (pool[i] != '\n' && pool[i] != '\0')
		i++;
	if (pool[i] == '\n')
		i++;
	buffer = (char *)malloc((i + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (pool[i] != '\n' && pool[i] != '\0')
	{
		buffer[i] = pool[i];
		i++;
	}
	if (pool[i] == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	return (buffer);
}

/*
ft_newpool - trims the line returned by ft_line from the pool. 
Reseting the start of the pool for next run of get_next_line.
*/

char	*ft_newpool(char *pool)
{
	int		i;
	int		j;
	char	*newpool;

	i = 0;
	j = 0;
	while (pool[i] != '\n' && pool[i] != '\0')
		i++;
	if (pool[i] == '\0')
	{
		free(pool);
		return (NULL);
	}
	i += (pool[i] == '\n');
	newpool = (char *)malloc((ft_strlen(pool) - i + 1) * sizeof(char));
	while (pool[i + j] != '\0')
	{
		newpool[j] = pool[i + j];
		j++;
	}
	newpool[j] = '\0';
	free(pool);
	return (newpool);
}

/*
get_next_line - setting temporary buffer string to read to, 
int bytes_read for fd guarding and indexing and static string pool to
continuous buffer saving.

Tests the fd read and BUFFER_SIZE size definiton.
|
Mallocs the buffer (+1 for '\0' - needed for using ft_strjoin). Guards it.
|
While loop - testing for '\n'in pool. Writes the buffer into the pool 
until there is one or until EOF.
Using READ to read from fd the size of BUFFER_SIZE. 
Using bytes_read to guard it and also adding the '\0'to the buffer.
Joins the pool with the buffer just read.
|
If newline - frees buffer and returning new buffer (line extracted 
from pool with ft_line). 
Trims the pool for next run.
*/

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_read;
	static char	*pool;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_test(pool) != 1 && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		pool = ft_write_pool(pool, buffer);
	}
	free(buffer);
	buffer = ft_line(pool);
	pool = ft_newpool(pool);
	return (buffer);
}
