/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:10:51 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/14 15:28:16 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init2(t_game *game)
{
	game->text.portal[0].img = mlx_xpm_file_to_image(game->mlx, PORTAL1,
			&game->text.portal[0].w, &game->text.portal[0].h);
	game->text.portal[1].img = mlx_xpm_file_to_image(game->mlx, PORTAL2,
			&game->text.portal[1].w, &game->text.portal[1].h);
	game->text.portal[2].img = mlx_xpm_file_to_image(game->mlx, PORTAL3,
			&game->text.portal[2].w, &game->text.portal[2].h);
	game->text.portal[3].img = mlx_xpm_file_to_image(game->mlx, PORTAL4,
			&game->text.portal[3].w, &game->text.portal[3].h);
	game->text.portal[4].img = mlx_xpm_file_to_image(game->mlx, PORTAL5,
			&game->text.portal[4].w, &game->text.portal[4].h);
	game->text.portal[5].img = mlx_xpm_file_to_image(game->mlx, PORTAL6,
			&game->text.portal[5].w, &game->text.portal[5].h);
	game->text.portal[6].img = mlx_xpm_file_to_image(game->mlx, PORTAL7,
			&game->text.portal[6].w, &game->text.portal[6].h);
	game->text.portal[7].img = mlx_xpm_file_to_image(game->mlx, PORTAL8,
			&game->text.portal[7].w, &game->text.portal[7].h);
}

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
	game->text.book.img = mlx_xpm_file_to_image(game->mlx, BOOK,
			&game->text.book.w, &game->text.book.h);
	game->text.zombie.img = mlx_xpm_file_to_image(game->mlx, ZOMBIE,
			&game->text.zombie.w, &game->text.zombie.h);
	game->text.bedrock.path = BEDROCK;
	game->text.dirt.path = DIRT;
	game->text.steve.path = STEVE;
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
	game->clock = 0;
	image_init(game);
}

void	game_init2(t_game *game)
{
	game->nb_diamond = nb_char(game, 'C');
	game->nb_zombie = nb_char(game, 'Z');
	game->portal_i = -1;
	game->text.portal = malloc(sizeof(t_img) * 8);
	game->c_pos = malloc(sizeof(t_axes) * game->nb_diamond);
	game->z_pos = malloc(sizeof(t_axes) * game->nb_zombie);
}

int	anime_loop(t_game *game)
{
	if (game->portal_i >= 0)
	{
		if (game->clock == 2000)
		{
			if (game->portal_i == 8)
				game->portal_i = 0;
			game->clock = 0;
			print_img(game->text.portal[game->portal_i], game, game->e_pos);
			game->portal_i++;
		}
		game->clock++;
	}
	return (0);
}
