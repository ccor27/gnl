/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:17:42 by crosorio          #+#    #+#             */
/*   Updated: 2025/06/09 14:51:01 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_two(char **ptr1, char **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

void	ft_update_stash(char **stash)
{
	int		i;
	char	*new_stash;

	if (stash || *stash)
	{
		i = 0;
		while ((*stash)[i] && (*stash)[i] != '\n')
			i++;
		if (!((*stash)[i]))
		{
			free(*stash);
			*stash = NULL;
		}
		else
		{
			new_stash = ft_strdup(*stash + i + 1);
			free(*stash);
			*stash = new_stash;
		}
	}
}

int	ft_read(int fd, char **stash, char **buffer)
{
	int		bytes_read;
	char	*tmp;

	while (1)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		else if (bytes_read == -1)
			return (0);
		(*buffer)[bytes_read] = '\0';
		tmp = ft_strjoin(*stash, *buffer, 0, 0);
		if (!tmp)
			return (0);
		free(*stash);
		*stash = tmp;
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_two(&stash[fd], &buffer));
	if (fd < 0 || fd >= MAX_FD || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free_two(&stash[fd], &buffer));
	if (!ft_read(fd, &stash[fd], &buffer))
		return (free_two(&stash[fd], &buffer));
	if (!stash[fd])
		return (free_two(&stash[fd], &buffer));
	line = ft_get_line(stash[fd]);
	ft_update_stash(&stash[fd]);
	if (!line || line[0] == '\0')
	{
		free(line);
		free_two(&stash[fd], &buffer);
		return (NULL);
	}
	free(buffer);
	return (line);
}
