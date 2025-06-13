/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-12 08:02:43 by crosorio          #+#    #+#             */
/*   Updated: 2025-06-12 08:02:43 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * Function to free 2 pointers and return NULL
 */
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

/**
 * Function to get a line after in the statsh is a \n or we
 * reached the end of the file
 */
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

/**
 * Function to update the stash after get the line, so basically
 * here we keep the remaining
 */
void	ft_update_stash(char **stash)
{
	int		i;
	char	*new_stash;

	if (!stash || !*stash)
		return ;
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

/**
 * Function to read from the file,
 * using a buffer's amount until reached file's end
 * or a \n
 */
int	ft_read(int fd, char **stash, char **buffer)
{
	int		bytes_read;
	char	*tmp;

	while (!ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		if (bytes_read == 0)
			break ;
		(*buffer)[bytes_read] = '\0';
		tmp = ft_strjoin(*stash, *buffer, 0, 0);
		if (!tmp)
			return (0);
		free(*stash);
		*stash = tmp;
	}
	return (1);
}
// Function that is called from the bonus main
char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	char		*buffer;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_two(&stash[fd], &buffer));
	if (!ft_read(fd, &stash[fd], &buffer))
		return (free_two(&stash[fd], &buffer));
	line = ft_get_line(stash[fd]);
	if (!line || line[0] == '\0')
		return (free(line), free_two(&stash[fd], &buffer));
	ft_update_stash(&stash[fd]);
	free(buffer);
	return (line);
}
