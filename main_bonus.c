/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 07:34:53 by crosorio          #+#    #+#             */
/*   Updated: 2025/06/12 17:08:08 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd1, fd2;
	char	*line1, *line2;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
		return (1);
	}

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		return (1);
	}

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 && !line2)
			break;
		if (line1)
		{
			printf("%s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("%s", line2);
			free(line2);
		}
	}

	close(fd1);
	close(fd2);
	return (0);
}
