/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:06:44 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/13 20:58:31 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	z_move_up(t_game *game, int i)
{
	t_axes	new_pos;

	new_pos.y = game->z_pos[i].y - 1;
	new_pos.x = game->z_pos[i].x;
	if (0 <= new_pos.y && new_pos.y < game->map_dim.y)
	{
		if (game->map[new_pos.y][new_pos.x] == '0')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			game->z_pos[i] = new_pos;
		}
		if (game->map[new_pos.y][new_pos.x] == 'P')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			ft_printf("Tu es mort\n");
			end(game);
		}
	}
}

void	z_move_down(t_game *game, int i)
{
	t_axes	new_pos;

	coords_p(game);
	new_pos.y = game->z_pos[i].y + 1;
	new_pos.x = game->z_pos[i].x;
	if (0 <= new_pos.y && new_pos.y < game->map_dim.y)
	{
		if (game->map[new_pos.y][new_pos.x] == '0')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			game->z_pos[i] = new_pos;
		}
		if (game->map[new_pos.y][new_pos.x] == 'P')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			ft_printf("Tu es mort\n");
			end(game);
		}
	}
}

void	z_move_left(t_game *game, int i)
{
	t_axes	new_pos;

	new_pos.y = game->z_pos[i].y;
	new_pos.x = game->z_pos[i].x - 1;
	if (0 <= new_pos.x && new_pos.x < game->map_dim.x)
	{
		if (game->map[new_pos.y][new_pos.x] == '0')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			game->z_pos[i] = new_pos;
		}
		if (game->map[new_pos.y][new_pos.x] == 'P')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			ft_printf("Tu es mort\n");
			end(game);
		}
	}
}

void	z_move_right(t_game *game, int i)
{
	t_axes	new_pos;

	coords_p(game);
	new_pos.y = game->z_pos[i].y;
	new_pos.x = game->z_pos[i].x + 1;
	if (0 <= new_pos.x && new_pos.x < game->map_dim.x)
	{
		if (game->map[new_pos.y][new_pos.x] == '0')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			game->z_pos[i] = new_pos;
		}
		if (game->map[new_pos.y][new_pos.x] == 'P')
		{
			game->map[new_pos.y][new_pos.x] = 'Z';
			game->map[game->z_pos[i].y][game->z_pos[i].x] = '0';
			print_img(game->text.dirt, game, game->z_pos[i]);
			overlay_img(game->text.zombie, game->text.dirt, game, new_pos);
			ft_printf("Tu es mort\n");
			end(game);
		}
	}
}

void	zombie_move(t_game *game)
{
	int		i;
	char	c[3];
	t_axes	pos;

	i = -1;
	c[0] = 'P';
	c[1] = '0';
	c[2] = '\0';
	coords_p(game);
	while (i++ < game->nb_zombie)
	{
		pos = game->z_pos[i];
		if (game->p_pos.x < pos.x && is_in(game->map[pos.y][pos.x - 1], c))
			z_move_left(game, i);
		else if (game->p_pos.x > pos.x && is_in(game->map[pos.y][pos.x + 1], c))
			z_move_right(game, i);
		else if (game->p_pos.y < pos.y && is_in(game->map[pos.y - 1][pos.x], c))
			z_move_up(game, i);
		else if (game->p_pos.y > pos.y && is_in(game->map[pos.y + 1][pos.x], c))
			z_move_down(game, i);
	}
}
