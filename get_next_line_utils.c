#include "get_next_line.h"

void	ft_free(t_list **lst)
{
	t_list	*aux;

	if (lst)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = aux;
		}
	}
}

int	there_is_newline(char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char		*s_copy;
	size_t		s_size;
	size_t		i;
	const char	*src;

	s_size = ft_strlen(s);
	s_copy = malloc((s_size + 1) * sizeof(char));
	if (!s_copy)
		return (NULL);
	if (!s && !s_copy)
		return (NULL);
	src = s;
	i = 0;
	while (i < s_size + 1)
	{
		s_copy[i] = src[i];
		i++;
	}
	return (s_copy);
}

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}

char	*ft_trim_string(char **string, int i, int j, int aux)
{
	char	*trimmed;
	char	*clean_content;

	if (!string)
		return (NULL);
	while (*string[i] && *string[i] != '\n')
		i++;
	if (*string[i] == '\n')
		i++;
	aux = i;
	trimmed = malloc((i + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed[i] = '\0';
	while (--i >= 0)
		trimmed[i] = *string[i];
	while (*string[aux])
		*string[j++] = *string[aux++];
	*string[j] = '\0';
	clean_content = ft_strdup(*string);
	if (!clean_content)
		return (NULL);
	free(*string);
	*string = clean_content;
	return (trimmed);
}
