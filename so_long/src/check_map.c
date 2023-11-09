/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:56:52 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/09 01:22:46 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_entity(char c)
{
	char	charset[6];
	int		i;

	charset[0] = '1';
	charset[1] = '0';
	charset[2] = 'P';
	charset[3] = 'C';
	charset[4] = 'E';
	charset[5] = '\0';
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(t_game *game)
{
	t_axes	size;
	t_axes	i;

	i.y = 0;
	size = game->map_dim;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			if (i.y == 0 || i.y == size.y - 1 || i.x == 0 || i.x == size.x - 1)
				if (game->map[i.y][i.x] != '1')
					return (0);
			if (is_entity(game->map[i.y][i.x]) == 0)
				return (-1);
			i.x++;
		}
		i.y++;
	}
	return (1);
}

void	set_entity(t_game *game, t_axes i, int *j)
{
	coords_p(game);
	if (game->map[i.y][i.x] == 'C')
	{
		game->c_pos[*j] = i;
		(*j)++;
		if (path_exist(game->p_pos, i, game) == 0)
			ft_error("Error collectible unreachable", game);
	}
	if (game->map[i.y][i.x] == 'E')
	{
		game->e_pos = i;
		if (path_exist(game->p_pos, i, game) == 0)
			ft_error("Error exit unreachable", game);
	}
}

void	get_entity_pos(t_game *game)
{
	t_axes		i;
	int			j;

	i.y = 0;
	j = 0;
	while (i.y < game->map_dim.y)
	{
		i.x = 0;
		while (i.x < game->map_dim.x)
		{
			set_entity(game, i, &j);
			i.x++;
		}
		i.y++;
	}
}

void	check_map(t_game *game)
{
	int	p;
	int	e;

	if (check_wall(game) == 0)
		ft_error("Error map not closed", game);
	if (check_wall(game) == -1)
		ft_error("Error unknown char", game);
	p = nb_char(game, 'P');
	e = nb_char(game, 'E');
	if (p != 1)
		ft_error("Error you should have one player", game);
	if (e != 1)
		ft_error("Error you should have one exit", game);
	if (game->nb_diamond < 1)
		ft_error("Error you should have at least one collectible", game);
	get_entity_pos(game);
}
