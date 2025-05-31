#include "get_next_line.h"

int	there_is_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (list->content[i])
	{
		if (list->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_know_line_size(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (list)
	{
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				i++;
				return (i);
			}
			else
				i++;
		}
		list = list->next;
	}
	return (i);
}

void	ft_fill_up_line(t_list *list, char *line, int size)
{
	int	i;

	if (!list || !line)
		return ;
	i = 0;
	while (list)
	{
		while (list->content[i])
		{
			line[i] = list->content[i];
			if (list->content[i] == '\n')
				break ;
			else
				i++;
		}
		list = list->next;
	}
	line[size] = '\0';
}
void	ft_trim_after_newline(t_list *node)
{
	char	*old;
	char	*new_content;
	int		i;
	int		j;

	if (!node || !node->content)
		return ;
	old = node->content;
	i = 0;
	while (old[i] && old[i] != '\n')
		i++;
	if (old[i] == '\n')
		i++;
	j = 0;
	while (old[i + j])
		j++;
	new_content = malloc(j + 1);
	if (!new_content)
		return ;
	j = 0;
	while (old[i])
		new_content[j++] = old[i++];
	new_content[j] = '\0';
	free(node->content);
	node->content = new_content;
}
