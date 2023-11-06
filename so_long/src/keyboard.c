/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:55:20 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/06 20:04:35 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coords_p(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_dim.y)
	{
		j = 0;
		while (j < game->map_dim.x)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_pos.x = j;
				game->p_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	move(t_game *game, t_axes new_pos)
{
	if (game->map[new_pos.y][new_pos.x] == '0')
		reload(game, new_pos);
	else if (game->map[new_pos.y][new_pos.x] == 'C')
	{
		game->nb_diamond--;
		reload(game, new_pos);
	}
	else if(game->map[new_pos.y][new_pos.x] == 'E')
	{
		if (game->nb_diamond == 0)
		{
			ft_printf("Bravo\n");
			free(game->mlx);
		}
	}
}

int	key_hook(int keybind, t_game *game)
{
	game->count += 1;
	if (keybind == K_UP)
		move_up(game);
	if (keybind == K_DOWN)
		move_down(game);
	if (keybind == K_LEFT)
		move_left(game);
	if (keybind == K_RIGHT)
		move_right(game);
	ft_printf("move nb = %d\n", game->count);
	ft_printf("nb diamond = %d\n", game->nb_diamond);
	return (0);
}
