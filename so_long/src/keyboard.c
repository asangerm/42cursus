/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:55:20 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/05 20:36:40 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define K_UP 119
#define K_DOWN 115
#define K_LEFT 97
#define K_RIGHT 100

void	coords_p(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y_map)
	{
		j = 0;
		while (j < game->x_map)
		{
			if (game->map[i][j] == 'P')
			{
				game->x_pos_p = j;
				game->y_pos_p = i;
			}
			j++;
		}
		i++;
	}
}

void	move_up(t_game *game)
{
	t_img	b_img;
	t_img	n_img;

	coords_p(game);
	if (0 <= game->y_pos_p - 1 && game->y_pos_p - 1 < game->y_map)
	{
		if (game->map[game->y_pos_p - 1][game->x_pos_p] == '0')
		{
			game->map[game->y_pos_p - 1][game->x_pos_p] = 'P';
			game->map[game->y_pos_p][game->x_pos_p] = '0';
			b_img.y_pos = game->x_pos_p;
			b_img.x_pos = game->y_pos_p;
			n_img.y_pos = game->x_pos_p;
			n_img.x_pos = game->y_pos_p - 1;
			print_img(&b_img, "./textures/dirt64.xpm", game);
			overlay_img(&n_img, "./textures/dirt64.xpm",
				"./textures/steve_prof2.xpm", game);
		}
	}
}

void	move_down(t_game *game)
{
	t_img	b_img;
	t_img	n_img;

	coords_p(game);
	if (0 <= game->y_pos_p + 1 && game->y_pos_p + 1 < game->y_map)
	{
		if (game->map[game->y_pos_p + 1][game->x_pos_p] == '0')
		{
			game->map[game->y_pos_p + 1][game->x_pos_p] = 'P';
			game->map[game->y_pos_p][game->x_pos_p] = '0';
			b_img.y_pos = game->x_pos_p;
			b_img.x_pos = game->y_pos_p;
			n_img.y_pos = game->x_pos_p;
			n_img.x_pos = (game->y_pos_p + 1);
			print_img(&b_img, "./textures/dirt64.xpm", game);
			overlay_img(&n_img, "./textures/dirt64.xpm",
				"./textures/steve_prof2.xpm", game);
		}
	}
}

void	move_left(t_game *game)
{
	t_img	b_img;
	t_img	n_img;

	coords_p(game);
	if (0 <= game->x_pos_p - 1 && game->x_pos_p - 1 < game->x_map)
	{
		if (game->map[game->y_pos_p][game->x_pos_p - 1] == '0')
		{
			game->map[game->y_pos_p][game->x_pos_p - 1] = 'P';
			game->map[game->y_pos_p][game->x_pos_p] = '0';
			b_img.y_pos = game->x_pos_p;
			b_img.x_pos = game->y_pos_p;
			n_img.y_pos = (game->x_pos_p - 1);
			n_img.x_pos = game->y_pos_p;
			print_img(&b_img, "./textures/dirt64.xpm", game);
			overlay_img(&n_img, "./textures/dirt64.xpm",
				"./textures/steve_prof2.xpm", game);
		}
	}
}

void	move_right(t_game *game)
{
	t_img	b_img;
	t_img	n_img;

	coords_p(game);
	if (0 <= game->x_pos_p + 1 && game->x_pos_p + 1 < game->x_map)
	{
		if (game->map[game->y_pos_p][game->x_pos_p + 1] == '0')
		{
			game->map[game->y_pos_p][game->x_pos_p + 1] = 'P';
			game->map[game->y_pos_p][game->x_pos_p] = '0';
			b_img.y_pos = game->x_pos_p;
			b_img.x_pos = game->y_pos_p;
			n_img.y_pos = (game->x_pos_p + 1);
			n_img.x_pos = game->y_pos_p;
			print_img(&b_img, "./textures/dirt64.xpm", game);
			overlay_img(&n_img, "./textures/dirt64.xpm",
				"./textures/steve_prof2.xpm", game);
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
