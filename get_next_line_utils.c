#include "get_next_line.h"

t_list	ft_free(t_list **lst)
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
	char	*s_copy;
	size_t	s_size;

	s_size = ft_strlen(s);
	s_copy = malloc((s_size + 1) * sizeof(char));
	if (!s_copy)
		return (NULL);
	ft_memcpy(s_copy, s, s_size + 1);
	return (s_copy);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}
