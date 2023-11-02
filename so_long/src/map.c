/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:55:07 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/02 18:45:48 by asangerm         ###   ########.fr       */
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
	char		*line;
	int			fd;

	fd = open(game->map_path, O_RDONLY);
	game->y_map = 0;
	game->x_map = 0;
	while (line != NULL || game->y_map == 0)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		if (game->y_map == 0)
			game->x_map = ft_strlen_no_endl(line);
		if ((int)ft_strlen_no_endl(line) != game->x_map)
			return ;
		game->y_map += 1;
	}
	close(fd);
	return ;
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

void	map_to_tab(t_game *game)
{
	int			fd;
	int			i;

	game->map = malloc(game->y_map * game->x_map);
	fd = open(game->map_path, O_RDONLY);
	i = 0;
	while (i < game->y_map)
	{
		game->map[i] = del_endl(get_next_line(fd));
		i++;
	}
	game->map[i] = (void *)0;
	close(fd);
	return ;
}
