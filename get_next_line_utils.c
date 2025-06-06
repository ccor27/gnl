#include "get_next_line.h"

void	ft_free(t_list **lst)
{
	t_list	*aux;

	if (*lst)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = aux;
		}
		free(aux);
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

// char	*ft_strdup(const char *s)
// {
// 	size_t	len;
// 	char	*copy;

// 	if (!s)
// 		return (NULL);
// 	len = ft_strlen(s);
// 	copy = malloc(len + 1);
// 	if (!copy)
// 		return (NULL);
// 	for (size_t i = 0; i < len; i++)
// 		copy[i] = s[i];
// 	copy[len] = '\0';
// 	return (copy);
// }

char *ft_strdup(const char *s)
{
    char *s_copy;
    size_t s_size;
    size_t i;

    if (!s)
        return (NULL);
    s_size = ft_strlen(s);
    s_copy = malloc(s_size + 1);
    if (!s_copy)
        return (NULL);
    i = 0;
    while (i <= s_size)
    {
        s_copy[i] = s[i];
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

	if (!string || !*string || **string == '\0')
		return (NULL);
	while ((*string)[i] && (*string)[i] != '\n')
		i++;
	if ((*string)[i] == '\n')
		i++;
	aux = i;
	trimmed = malloc((i + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed[i] = '\0';
	while (--i >= 0)
		trimmed[i] = (*string)[i];
	while ((*string)[aux])
		(*string)[j++] = (*string)[aux++];
	(*string)[j] = '\0';
	clean_content = ft_strdup(*string);
	if (!clean_content)
		return (NULL);
	free(*string);
	*string = clean_content;
	free(clean_content);
	return (trimmed);
}
