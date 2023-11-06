/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:55:20 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/06 17:12:46 by asangerm         ###   ########.fr       */
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

void	reload()
{
	t_img	b_img;
	t_img	n_img;


}

void	move_up(t_game *game)
{
	t_img	b_img;
	t_img	n_img;
	t_axes	new_pos;

	coords_p(game);
	new_pos.y = game->p_pos.y - 1;
	new_pos.x = game->p_pos.x;
	if (0 <= game->p_pos.y - 1 && game->p_pos.y - 1 < game->map_dim.y)
	{
		if (game->map[game->p_pos.y - 1][game->p_pos.x] == '0')
		{
			game->map[game->p_pos.y - 1][game->p_pos.x] = 'P';
			game->map[game->p_pos.y][game->p_pos.x] = '0';
			b_img.img_pos = game->p_pos;
			n_img.img_pos.x = game->p_pos.x;
			n_img.img_pos.y = game->p_pos.y - 1;
			print_img(&b_img, DIRT, game);
			overlay_img(&n_img, DIRT, STEVE, game);
		}
	}
}

void	move_down(t_game *game)
{
	t_img	b_img;
	t_img	n_img;

	coords_p(game);
	if (0 <= game->p_pos.y + 1 && game->p_pos.y + 1 < game->map_dim.y)
	{
		if (game->map[game->p_pos.y + 1][game->p_pos.x] == '0')
		{
			game->map[game->p_pos.y + 1][game->p_pos.x] = 'P';
			game->map[game->p_pos.y][game->p_pos.x] = '0';
			b_img.img_pos = game->p_pos;
			n_img.img_pos.x = game->p_pos.x;
			n_img.img_pos.y = (game->p_pos.y + 1);
			print_img(&b_img, DIRT, game);
			overlay_img(&n_img, DIRT, STEVE, game);
		}
	}
}

void	move_left(t_game *game)
{
	t_img	b_img;
	t_img	n_img;

	coords_p(game);
	if (0 <= game->p_pos.x - 1 && game->p_pos.x - 1 < game->map_dim.x)
	{
		if (game->map[game->p_pos.y][game->p_pos.x - 1] == '0')
		{
			game->map[game->p_pos.y][game->p_pos.x - 1] = 'P';
			game->map[game->p_pos.y][game->p_pos.x] = '0';
			b_img.img_pos = game->p_pos;
			n_img.img_pos.x = (game->p_pos.x - 1);
			n_img.img_pos.y = game->p_pos.y;
			print_img(&b_img, DIRT, game);
			overlay_img(&n_img, DIRT, STEVE, game);
		}
	}
}

void	move_right(t_game *game)
{
	t_img	b_img;
	t_img	n_img;

	coords_p(game);
	if (0 <= game->p_pos.x + 1 && game->p_pos.x + 1 < game->map_dim.x)
	{
		if (game->map[game->p_pos.y][game->p_pos.x + 1] == '0')
		{
			game->map[game->p_pos.y][game->p_pos.x + 1] = 'P';
			game->map[game->p_pos.y][game->p_pos.x] = '0';
			b_img.img_pos = game->p_pos;
			n_img.img_pos.x = (game->p_pos.x + 1);
			n_img.img_pos.y = game->p_pos.y;
			print_img(&b_img, DIRT, game);
			overlay_img(&n_img, DIRT, STEVE, game);
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
	return (0);
}
