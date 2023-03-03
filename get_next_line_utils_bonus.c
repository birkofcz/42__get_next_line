/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:33:16 by sbenes            #+#    #+#             */
/*   Updated: 2023/02/26 13:33:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
ft_strlen - for string measuring - standard from my libft
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
ft_write_pool - extra function - taking care of pool creation and its 
guarding, using standard ft_strjoin from my libft. If no pool, creates 
one with '\0'so it can be used by ft_strjoin. Strjoin making new pool. 
Freeing the former one. 
*/

char	*ft_write_pool(char *pool, char *buffer)
{
	char	*written_pool;

	if (!pool)
	{
		pool = (char *)malloc(1 * sizeof(char));
		pool[0] = '\0';
	}
	if (!pool || !buffer)
		return (NULL);
	written_pool = ft_strjoin(pool, buffer);
	free(pool);
	return (written_pool);
}

/*
ft_strjoin - my libft version. Used for writing buffer into the pool.
*/

char	*ft_strjoin(char *pool, char *buffer)
{
	char	*joined_str;
	size_t	size;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!pool || !buffer)
		return (NULL);
	size = ft_strlen(pool) + ft_strlen(buffer) + 1;
	joined_str = (char *)malloc(size * sizeof(char));
	if (!joined_str)
		return (NULL);
	while (pool[i] != '\0')
	{
		joined_str[i] = pool[i];
		i++;
	}
	while (buffer[y] != '\0')
	{
		joined_str[i++] = buffer[y++];
	}
	joined_str[i] = '\0';
	return (joined_str);
}
