/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:08:58 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/06 16:41:30 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_img *img, char *path, t_game *game)
{
	img->texture = path;
	img->img = mlx_xpm_file_to_image(game->mlx, img->texture,
			&img->img_dim.x, &img->img_dim.y);
	mlx_put_image_to_window(game->mlx, game->win, img->img,
		img->img_pos.x * 64, img->img_pos.y * 64);
}

void	merge_img(t_img *img, t_img *fg, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->img_dim.y)
	{
		x = 0;
		while (x < img->img_dim.x)
		{
			if (fg->data[(y * fg->size_line) + (x * (fg->bpp / 8))] != 0)
			{
				img->data[(y * img->size_line) + (x * (img->bpp / 8))]
					= fg->data[(y * fg->size_line) + (x * (fg->bpp / 8))];
				img->data[(y * img->size_line) + (x * (img->bpp / 8) + 1)]
					= fg->data[(y * fg->size_line) + (x * (fg->bpp / 8) + 1)];
				img->data[(y * img->size_line) + (x * (img->bpp / 8) + 2)]
					= fg->data[(y * fg->size_line) + (x * (fg->bpp / 8) + 2)];
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, img->img,
		img->img_pos.x * 64, img->img_pos.y * 64);
}

void	overlay_img(t_img *img, char *pathb, char *pathf, t_game *game)
{
	t_img	fg;

	fg.texture = pathf;
	fg.img = mlx_xpm_file_to_image(game->mlx, fg.texture,
			&fg.img_dim.x, &fg.img_dim.y);
	fg.img_pos = img->img_pos;
	fg.data = mlx_get_data_addr(fg.img, &fg.bpp, &fg.size_line, &fg.endian);
	img->texture = pathb;
	img->img = mlx_xpm_file_to_image(game->mlx, img->texture,
			&img->img_dim.x, &img->img_dim.y);
	img->data = mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	merge_img(img, &fg, game);
}

void	display_map(t_game *game)
{
	t_img	img;

	img.img_pos.y = 0;
	while (img.img_pos.y < game->map_dim.y)
	{
		img.img_pos.x = 0;
		while (img.img_pos.x < game->map_dim.x)
		{
			if (game->map[img.img_pos.y][img.img_pos.x] == '1')
				print_img(&img, BEDROCK, game);
			else if (game->map[img.img_pos.y][img.img_pos.x] == '0')
				print_img(&img, DIRT, game);
			else if (game->map[img.img_pos.y][img.img_pos.x] == 'E')
				print_img(&img, PORTAL, game);
			else if (game->map[img.img_pos.y][img.img_pos.x] == 'P')
				overlay_img(&img, DIRT, STEVE, game);
			else if (game->map[img.img_pos.y][img.img_pos.x] == 'C')
				overlay_img(&img, DIRT, DIAMOND, game);
			img.img_pos.x++;
		}
		img.img_pos.y++;
	}
}
