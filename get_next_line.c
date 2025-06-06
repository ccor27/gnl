#include "get_next_line.h"

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

char	*ft_update_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	return (new_stash);
}

int	ft_read(int fd, char *stash)
{
	int		bytes_read;
	char	*tmp;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		else if (bytes_read == -1)
			return (0); // error, free line
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer,0,0);
		free(stash);
		stash = tmp;
		// free tmp ?
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_read(fd, stash))
	{
		free(stash);
		return (NULL);
	}
	line = ft_get_line(stash);
	if (!line)
		return (NULL); // free ??
	stash = ft_update_stash(stash);
	return (line);
}
