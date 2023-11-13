/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:10:51 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/13 15:22:28 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(t_game *game)
{
	game->text.dirt.img = mlx_xpm_file_to_image(game->mlx, DIRT,
			&game->text.dirt.w, &game->text.dirt.h);
	game->text.bedrock.img = mlx_xpm_file_to_image(game->mlx, BEDROCK,
			&game->text.bedrock.w, &game->text.bedrock.h);
	game->text.steve.img = mlx_xpm_file_to_image(game->mlx, STEVE,
			&game->text.steve.w, &game->text.steve.h);
	game->text.diamond.img = mlx_xpm_file_to_image(game->mlx, DIAMOND,
			&game->text.diamond.w, &game->text.diamond.h);
	game->text.portal.img = mlx_xpm_file_to_image(game->mlx, PORTAL,
			&game->text.portal.w, &game->text.portal.h);
	game->text.book.img = mlx_xpm_file_to_image(game->mlx, BOOK,
			&game->text.book.w, &game->text.book.h);
	game->text.zombie.img = mlx_xpm_file_to_image(game->mlx, ZOMBIE,
			&game->text.zombie.w, &game->text.zombie.h);
	game->text.bedrock.path = BEDROCK;
	game->text.dirt.path = DIRT;
	game->text.steve.path = STEVE;
	game->text.portal.path = PORTAL;
	game->text.diamond.path = DIAMOND;
	game->text.book.path = BOOK;
	game->text.zombie.path = ZOMBIE;
}

void	game_init(t_game *game)
{
	game->win = NULL;
	game->map = NULL;
	game->map_dim.x = 0;
	game->map_dim.y = 0;
	game->nb_diamond = 0;
	game->count = 0;
	game->p_pos.x = 0;
	game->p_pos.y = 0;
	game->c_pos = NULL;
	game->z_pos = NULL;
	image_init(game);
}
