/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:46:18 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/17 19:01:43 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	void	*temp;

	temp = s;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)s = c;
		i++;
		s++;
	}
	return (temp);
}

char	*ft_a_next_line(int fd, char *str)
{
	char		*buf;
	int			isread;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	isread = 42;
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	while (!ft_strrchr(buf, '\n') && isread != 0)
	{
		isread = read(fd, buf, BUFFER_SIZE);
		if (isread == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[isread] = '\0';
		if (str == NULL && isread != 0)
			str = ft_strdup(buf);
		else if (isread != 0)
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
	while (str[i] && str[i] != '\n')
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
	if (!str[strlen] || (strlen == 0 && str[strlen] != '\n'))
	{
		free(str);
		return (NULL);
	}
	newstr = malloc(sizeof(char) * (ft_strlen(str) - strlen + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[strlen++])
		newstr[i++] = str[strlen];
	newstr[i] = '\0';
	free (str);
	if (newstr[0] == '\0')
	{
		free(newstr);
		return (NULL);
	}
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
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line 1 = %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 2 = %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 3 = %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 4 = %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 5 = %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 6 = %s\n", line);
	free(line);
	close(fd);
	return (0);
}
*/
