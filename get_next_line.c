#include "get_next_line.h"

char	*ft_prepare_next_call(t_list **list)
{
	int		i;
	t_list	*head;
	t_list *aux;
	char *line;

	head = *list;
	line = 0;
	i = 0;
	while (head)
	{
		if(!there_is_newline(head->content))
		{
			line = ft_strjoin(line, head->content,0,0);
			aux = head->next;
			free(head->content);
			free(head);
			head = aux;
		}
		else
		{
			
		}
	}

	return(line);
}
int	append_node(t_list **list, char *string)
{
	t_list	*current;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = ft_strdup(string);
	if (!new_node->content)
		return (0);
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return (1);
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (1);
}
int	ft_read(int fd, t_list **list, char *buffer)
{
	int	bytes_read;
	int	flag;

	flag = 1;
	while (flag)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		else if (bytes_read == -1)
			return (0);
		buffer[bytes_read] = '\0';
		if (!append_node(list, buffer))
			return (0);
		if (there_is_newline(buffer))
			flag = 0;
	}
	free(buffer);
	return (1);
}
char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;
	char			*buffer;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!ft_read(fd, &list, buffer))
	{
		free(buffer);
		return (ft_free_list(&list));
	}
}
// read
// get line
// prepare to next call
// return
/**
 * get the line
 */

char	*ft_strjoin(char const *s1, char const *s2, size_t len1, size_t len2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < len2)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
