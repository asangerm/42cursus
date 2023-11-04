/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:55:20 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/04 21:24:42 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define k_up 119
#define k_down 115
#define k_left 97
#define k_right 100

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
	int	x;
	int	y;

	coords_p(game);
	x = game->x_pos_p;
	y = game->y_pos_p - 1;
	if (0 <= y && y < game->y_map)
	{
		//ft_printf("map_x = %d, map_y = %d\n", x, y);
		if (game->map[y][x] == '0')
		{
			game->map[y][x] = 'P';
			game->map[y+1][x] = '0';
			//ft_printf("x : %d, y = %d\n", game->x_pos_p, game->y_pos_p);
		}
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	coords_p(game);
	x = game->x_pos_p;
	y = game->y_pos_p + 1;
	if (0 <= y && y < game->y_map)
	{
		//ft_printf("map_x = %d, map_y = %d\n", x, y);
		if (game->map[y][x] == '0')
		{
			game->map[y][x] = 'P';
			game->map[y-1][x] = '0';
			//ft_printf("x : %d, y = %d\n", game->x_pos_p, game->y_pos_p);
		}
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	coords_p(game);
	x = game->x_pos_p - 1;
	y = game->y_pos_p;
	if (0 <= x && x < game->x_map)
	{
		//ft_printf("map_x = %d, map_y = %d\n", x, y);
		if (game->map[y][x] == '0')
		{
			game->map[y][x] = 'P';
			game->map[y][x + 1] = '0';
			//ft_printf("x : %d, y = %d\n", game->x_pos_p, game->y_pos_p);
		}
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	coords_p(game);
	x = game->x_pos_p + 1;
	y = game->y_pos_p;
	if (0 <= x && x < game->x_map)
	{
		//ft_printf("map_x = %d, map_y = %d\n", x, y);
		if (game->map[y][x] == '0')
		{
			game->map[y][x] = 'P';
			game->map[y][x - 1] = '0';
			//ft_printf("x : %d, y = %d\n", game->x_pos_p, game->y_pos_p);
		}
	}
}

int	key_hook(int keybind, t_game *game)
{
	game->count += 1;
	if (keybind == k_up)
		move_up(game);
	if (keybind == k_down)
		move_down(game);
	if (keybind == k_left)
		move_left(game);
	if (keybind == k_right)
		move_right(game);
	display_map(game);
	//ft_printf("%d\n", keybind);
	//ft_printf("%d\n", game->count);
	return (0);
}
