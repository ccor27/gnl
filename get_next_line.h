#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;
int there_is_newline(t_list *list);
void read_file(t_list **list, int fd);
void	append_node(t_list **list, char *string);
char	*ft_get_line(t_list **list);
void	ft_fill_up_line(t_list *list, char *line, int size);
int	ft_know_line_size(t_list *list);
t_list	*ft_lstnew(char *content);
char	*get_next_line(int fd);
void	ft_trim_after_newline(t_list *node);
#endif
