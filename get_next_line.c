#include "get_next_line.h"

void	ft_prepare_list_next_call(t_list **list)
{
	t_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		if (there_is_newline(*list))
			break ;
		else
		{
			temp = (*list)->next;
			free((*list)->content);
			free(*list);
			*list = temp;
		}
	}
	ft_trim_after_newline(*list);
}

char	*ft_get_line(t_list **list)
{
	int		line_size;
	char	*line;

	line_size = ft_know_line_size(*list);
	line = malloc((line_size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_fill_up_line(*list, line, line_size);
	return (line);
}

void	append_node(t_list **list, char *string)
{
	t_list	*current;
	t_list	*new_node;

	new_node = ft_lstnew(string);
	if (!new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new_node;
}
void	read_file(t_list **list, int fd)
{
	int		bytes_read;
	char	*buffer;

	while (!there_is_newline(*list))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		append_node(list, buffer);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file(&list, fd);
	line = ft_get_line(&list);
	ft_prepare_list_next_call(&list);
	return(line);
}
