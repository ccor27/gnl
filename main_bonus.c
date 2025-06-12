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

#define MAX_TEST_FDS 100
/*
 int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("texto1.txt", O_RDONLY);
	fd2 = open("texto2.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error al abrir los archivos");
		return (1);
	}
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if(!line1 && !line2)
			break;
		if (line1)
		{
			printf("FD1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("FD2: %s", line2);
			free(line2);
		}

	}

	close(fd1);
	close(fd2);
	return (0);
} */
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("example.txt", O_RDONLY);
	fd2 = open("quijote.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error al abrir los archivos");
		return (1);
	}
	while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
	{
		if (line1)
		{
			printf("FD1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("FD1: %s", line2);
			free(line2);
		}

	}

	close(fd1);
	close(fd2);
	return (0);
}
// int	main(int argc, char **argv)
// {
// 	int		fds[MAX_TEST_FDS];
// 	char	*line;
// 	int		active;
// 	int		i;

// 	active = 0;
// 	if (argc < 2)
// 	{
// 		fprintf(stderr, "Uso: %s <archivo1> <archivo2> ...\n", argv[0]);
// 		return (1);
// 	}
// 	if (argc - 1 > MAX_TEST_FDS)
// 	{
// 		fprintf(stderr, "Máximo de archivos soportados: %d\n", MAX_TEST_FDS);
// 		return (1);
// 	}
// 	// Abrimos los archivos
// 	for (i = 0; i < argc - 1; i++)
// 	{
// 		fds[i] = open(argv[i + 1], O_RDONLY);
// 		if (fds[i] < 0)
// 		{
// 			perror("Error al abrir archivo");
// 			return (1);
// 		}
// 	}
// 	active = argc - 1;
// 	// Leemos línea por línea, alternando FDs
// 	while (active > 0)
// 	{
// 		for (i = 0; i < argc - 1; i++)
// 		{
// 			if (fds[i] == -1)
// 				continue ;
// 			line = get_next_line(fds[i]);
// 			if (line)
// 			{
// 				printf("%s", line);
// 				free(line);
// 			}
// 			else
// 			{
// 				close(fds[i]);
// 				fds[i] = -1;
// 				active--;
// 			}
// 		}
// 	}
// 	return (0);
// }
