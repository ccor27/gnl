#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_lenght;
	size_t	i;
	char	*sub;

	s_lenght = ft_strlen(s);
	i = 0;
	if (start >= s_lenght)
		return (ft_strdup(""));
	if (len > s_lenght - start)
		len = s_lenght - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_lenght;

	i = 0;
	s_lenght = ft_strlen(s);
	while (i < s_lenght)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < s1_len)
		new_string[i] = s1[i++];
	j = 0;
	while (j < s2_len)
		new_string[i + j] = s2[j++];
	new_string[i + j] = '\0';
	return (new_string);
}
