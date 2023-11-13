/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:39:18 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/13 15:14:14 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reload(t_game *game, t_axes new_pos)
{
	game->map[new_pos.y][new_pos.x] = 'P';
	game->map[game->p_pos.y][game->p_pos.x] = '0';
	print_img(game->text.dirt, game, game->p_pos);
	overlay_img(game->text.steve, game->text.dirt, game, new_pos);
	game->count += 1;
	ft_printf("move nb = %d\n", game->count);
	display_moves(game);
	if (game->count % 2 == 0)
		zombie_move(game);
}

void	move_up(t_game *game)
{
	t_axes	new_pos;

	coords_p(game);
	new_pos.y = game->p_pos.y - 1;
	new_pos.x = game->p_pos.x;
	if (0 <= new_pos.y && new_pos.y < game->map_dim.y)
	{
		move(game, new_pos);
	}
}

void	move_down(t_game *game)
{
	t_axes	new_pos;

	coords_p(game);
	new_pos.y = game->p_pos.y + 1;
	new_pos.x = game->p_pos.x;
	if (0 <= new_pos.y && new_pos.y < game->map_dim.y)
	{
		move(game, new_pos);
	}
}

void	move_left(t_game *game)
{
	t_axes	new_pos;

	coords_p(game);
	new_pos.y = game->p_pos.y;
	new_pos.x = game->p_pos.x - 1;
	if (0 <= new_pos.x && new_pos.x < game->map_dim.x)
	{
		move(game, new_pos);
	}
}

void	move_right(t_game *game)
{
	t_axes	new_pos;

	coords_p(game);
	new_pos.y = game->p_pos.y;
	new_pos.x = game->p_pos.x + 1;
	if (0 <= new_pos.x && new_pos.x < game->map_dim.x)
	{
		move(game, new_pos);
	}
}
