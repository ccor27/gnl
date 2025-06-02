/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:50:28 by crosorio          #+#    #+#             */
/*   Updated: 2025/05/28 15:55:48 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_store_and_free(char *content, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(content, buffer);
	free(content);
	return (temp);
}

char	*ft_get_content(int fd, char *buffer)
{
	char	*content;
	int	bytes_read;

	content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, content, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(content);
			return (NULL);
		}
		content[bytes_read] = '\0';
		buffer = ft_store_and_free(buffer, content);
		if (ft_strchr(content, '\n'))
			break ;
	}
	free(content);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	// int	i;

	// if (!buffer)
	// 	return (NULL);
	// i = 0;
	// while (buffer[i] && buffer[i] != '\n')
	// 	i++;
	// return (ft_substr(buffer, 0, i));
}

char	*ft_get_next(char *buffer)
{
	int	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (ft_substr(buffer, i, ft_strlen(buffer)));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_content(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_next(buffer);
	return (line);
}
/*
 TODO:
		- validate that the file descriptor has value (fd>0)
		- validate if there is content to read using read function (read(fd,0,0) > 0)
		- validate if the buffer_size is 0 or less
		- get the characters especified by the buffer_size into buffer using read
		- process the characters until the \n the rest left it in the buffer
*/
