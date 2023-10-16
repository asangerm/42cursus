/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:46:18 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/16 21:47:19 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		*buf;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	while (!ft_strrchr(buf, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
		if (str == NULL)
			str = buf;
		else
			ft_strjoin(str, buf);
	}
	line = str;
	return (line);
}

#include <stdio.h>

int main (void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}