/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:18:14 by crosorio          #+#    #+#             */
/*   Updated: 2025/06/12 17:07:43 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
//-o gnl_test
// valgrind --leak-check=full --show-leak-kinds=all ./gnl_test 1char.txt
/* int	main(int argc, char **argv)
{
	int fd;
	char *line;
	if(argc != 2)
		return (1);
	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
		return(1);
	while((line = get_next_line(999)))
	{
		printf("%s",line);
		free(line);
	}
	close(fd);
	return(0);
} */
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
