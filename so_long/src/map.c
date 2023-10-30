/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:55:07 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/30 15:27:53 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_strlen_no_endl(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (ft_strchr(str, '\n') != NULL)
		return (len - 1);
	return (len);
}

static t_size_m	set_zero_err(t_size_m size_m)
{
	size_m.w = 0;
	size_m.h = 0;
	return (size_m);
}

t_size_m	map_size(char *file)
{
	char		*line;
	t_size_m	size_m;
	int			fd;

	fd = open(file, O_RDONLY);
	size_m.w = 0;
	while (line != NULL || size_m.w == 0)
	{
		line = get_next_line(fd);
		if (!line)
			return (size_m);
		if (size_m.w == 0)
			size_m.h = ft_strlen_no_endl(line);
		if (ft_strlen_no_endl(line) != size_m.h)
			return (set_zero_err(size_m));
		size_m.w += 1;
	}
	close(fd);
	return (size_m);
}

char	*del_endl(char *str)
{
	char	*new;
	int		i;

	if (!ft_strchr(str, '\n'))
		return (str);
	new = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	**map_to_tab(char *file, t_size_m size_m)
{
	char		**tab;
	int			fd;
	size_t		i;

	tab = malloc(size_m.h * (size_m.w + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while(i < size_m.w)
	{
		tab[i] = del_endl(get_next_line(fd));
		i++;
	}
	tab[i] = (void *)0;
	close(fd);
	return(tab);
}
