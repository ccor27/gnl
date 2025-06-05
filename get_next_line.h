#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;
// get_next_line_utils.c
void				ft_free(t_list **lst);
int					there_is_newline(char *string);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_trim_string(char **string, int i, int j, int aux);
// get_next_line.c
char	*ft_prepare_next_call(t_list **list, char *trimmed, char *tmp);
int					append_node(t_list **list, char *string);
int					ft_read(int fd, t_list **list, char *buffer);
char				*get_next_line(int fd);
char				*ft_strjoin(char const *s1, char const *s2, size_t len1,
						size_t len2);
#endif
