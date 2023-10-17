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

char	*ft_a_next_line(int fd, char *str)
{
	char		*buf;
	int			isread;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	isread = 42;
	while (!ft_strrchr(buf, '\n') && isread != 0)
	{
		isread = read(fd, buf, BUFFER_SIZE);
		if (isread == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[isread] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_the_real_line(char *str)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * (ft_strlen_endl(str) + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] || str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_newstr(char *str)
{
	int		strlen;
	int		i;
	char	*newstr;

	strlen = ft_strlen_endl(str);
	if (!str[strlen])
	{
		free(str);
		return (NULL);
	}
	newstr = malloc(sizeof(char) * (ft_strlen(str) - strlen + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	strlen++;
	while (str[strlen])
	{
		newstr[i] = str[strlen];
		i++;
		strlen++;
	}
	newstr[i] = '\0';
	free (str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_a_next_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_the_real_line(str);
	str = ft_newstr(str);
	return (line);
}

/*
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main (void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
*/