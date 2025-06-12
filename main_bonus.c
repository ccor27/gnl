/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-12 07:34:53 by crosorio          #+#    #+#             */
/*   Updated: 2025-06-12 07:34:53 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TEST_FDS 100

int	main(int argc, char **argv)
{
	int		fds[MAX_TEST_FDS];
	char	*line;
	int		active;
	int		i;

	active = 0;
	if (argc < 2)
	{
		fprintf(stderr, "Uso: %s <archivo1> <archivo2> ...\n", argv[0]);
		return (1);
	}
	if (argc - 1 > MAX_TEST_FDS)
	{
		fprintf(stderr, "Máximo de archivos soportados: %d\n", MAX_TEST_FDS);
		return (1);
	}
	// Abrimos los archivos
	for (i = 0; i < argc - 1; i++)
	{
		fds[i] = open(argv[i + 1], O_RDONLY);
		if (fds[i] < 0)
		{
			perror("Error al abrir archivo");
			return (1);
		}
	}
	active = argc - 1;
	// Leemos línea por línea, alternando FDs
	while (active > 0)
	{
		for (i = 0; i < argc - 1; i++)
		{
			if (fds[i] == -1)
				continue ;
			line = get_next_line(fds[i]);
			if (line)
			{
				printf("%s", line);
				free(line);
			}
			else
			{
				close(fds[i]);
				fds[i] = -1;
				active--;
			}
		}
	}
	return (0);
}
