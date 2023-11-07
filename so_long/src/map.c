/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:55:07 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/07 17:17:43 by asangerm         ###   ########.fr       */
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

void	map_size(t_game *game)
{
	char	*line;
	int		fd;

	fd = open(game->map_path, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL || game->map_dim.y == 0)
	{
		if (game->map_dim.y == 0)
			game->map_dim.x = ft_strlen_no_endl(line);
		if ((int)ft_strlen_no_endl(line) != game->map_dim.x)
			{
				ft_printf("Map not compliant");
				end(game);
			}
		game->map_dim.y += 1;
	}
	close(fd);
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

char	**map_to_tab(t_game *game)
{
	int			fd;
	int			i;
	char		**map;

	map = malloc(game->map_dim.y * game->map_dim.x);
	fd = open(game->map_path, O_RDONLY);
	i = 0;
	while (i < game->map_dim.y)
	{
		map[i] = del_endl(get_next_line(fd));
		i++;
	}
	map[i] = (void *)0;
	close(fd);
	return (map);
}
