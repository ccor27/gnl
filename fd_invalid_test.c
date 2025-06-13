/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_invalid_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-13 09:34:38 by crosorio          #+#    #+#             */
/*   Updated: 2025-06-13 09:34:38 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Main to test an invalid fd in the mandatory part
int	main(void)
{
	char	*line;

	line = get_next_line(-1);
	if (!line)
		printf("✅OK fd -1\n");
	else
	{
		printf("❌FAIL fd -1: %s\n", line);
		free(line);
	}
	line = get_next_line(42);
	if (!line)
		printf("✅OK fd 42\n");
	else
	{
		printf("❌FAIL fd 42: %s\n", line);
		free(line);
	}
	line = get_next_line(1000);
	if (!line)
		printf("✅OK fd 1000\n");
	else
	{
		printf("❌FAIL fd 1000: %s\n", line);
		free(line);
	}
	return (0);
}
