#include "get_next_line.h"

char *ft_store_and_free()
{

}
char *ft_get_content(int fd)
{

    /*
    - use the read to get characters and store it in a variable
    - each time we use the read validate if it has a \n, if it so, stop reading
    */
    char *buffer;
    char *content;
    size_t bytes_read;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buffer)
        return (NULL);
    bytes_read = 1;
    while(bytes_read > 0)
    {
        bytes_read = read(fd,buffer,BUFFER_SIZE);
        if( bytes_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read]='\0';
        content = ft_store_and_free();
        if(ft_strchr(content,"\n"))
            break;
    }
    return (buffer);
}

char *ft_get_line(char *buffer)
{

}
char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if(fd < 0 || read(fd,0,0) < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    buffer = ft_get_content(fd);
    if(!buffer)
        return (NULL);
    line = ft_get_line(buffer);
    /*
     TODO:
            - validate that the file descriptor has value (fd>0)
            - validate if there is content to read using read function (read(fd,0,0) > 0)
            - validate if the buffer_size is 0 or less
            - get the characters especified by the buffer_size into buffer using read
            - process the characters until the \n the rest left it in the buffer
    */
}
