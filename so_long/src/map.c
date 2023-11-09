/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:55:07 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/09 01:49:16 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	end(game);
}

static int	get_file_size(t_game *game)
{
	int		fd;
	int		size;
	char	c;

	fd = open(game->map_path, O_RDONLY);
	if (fd == -1)
		ft_error("Error open file", game);
	size = 0;
	while (read(fd, &c, 1) > 0)
		size++;
	close(fd);
	return (size);
}

char	*file_to_str(t_game *game)
{
	int		size;
	int		fd;
	int		i;
	char	c;
	char	*str;

	i = 0;
	size = get_file_size(game);
	fd = open(game->map_path, O_RDONLY);
	if (fd == -1)
		ft_error("Error open file", game);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		ft_error("Error malloc str", game);
	while (i < size)
	{
		read(fd, &c, 1);
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

char	**str_to_tab(char *str)
{
	char	**map;

	map = ft_split(str, '\n');
	free(str);
	return (map);
}

t_axes	map_size(t_game *game)
{
	t_axes	i;

	i.y = 0;
	i.x = ft_strlen(game->map[i.y]);
	while (game->map[i.y])
	{
		if ((int)ft_strlen(game->map[i.y]) != i.x)
			ft_error("Error map bad shape", game);
		i.y++;
	}
	return (i);
}
