#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

// get_next_line_utils.c
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2, size_t i, size_t j);
// get_next_line.c
char *ft_get_line(char *stash);
char *ft_update_stash(char *stash);
int					ft_read(int fd, char *stash);
char				*get_next_line(int fd);
#endif
