/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:08:58 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/05 20:13:13 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_img *img, char *path, t_game *game)
{
	img->texture = path;
	img->img = mlx_xpm_file_to_image(game->mlx, img->texture,
			&img->x_img, &img->y_img);
	mlx_put_image_to_window(game->mlx, game->win, img->img,
		img->y_pos * 64, img->x_pos * 64);
}

void	merge_img(t_img *img, t_img *fg, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->y_img)
	{
		x = 0;
		while (x < img->x_img)
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
		img->y_pos * 64, img->x_pos * 64);
}

void	overlay_img(t_img *img, char *pathb, char *pathf, t_game *game)
{
	t_img	fg;

	fg.texture = pathf;
	fg.img = mlx_xpm_file_to_image(game->mlx, fg.texture,
			&fg.x_img, &fg.y_img);
	fg.x_pos = img->x_pos;
	fg.y_pos = img->y_pos;
	fg.data = mlx_get_data_addr(fg.img, &fg.bpp, &fg.size_line, &fg.endian);
	img->texture = pathb;
	img->img = mlx_xpm_file_to_image(game->mlx, img->texture,
			&img->x_img, &img->y_img);
	img->data = mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	merge_img(img, &fg, game);
}

void	display_map(t_game *game)
{
	t_img	img;

	img.x_pos = 0;
	while (img.x_pos < game->y_map)
	{
		img.y_pos = 0;
		while (img.y_pos < game->x_map)
		{
			if (game->map[img.x_pos][img.y_pos] == '1')
				print_img(&img, "./textures/bedrock64.xpm", game);
			else if (game->map[img.x_pos][img.y_pos] == '0')
				print_img(&img, "./textures/dirt64.xpm", game);
			else if (game->map[img.x_pos][img.y_pos] == 'E')
				print_img(&img, "./textures/nether_portal64.xpm", game);
			else if (game->map[img.x_pos][img.y_pos] == 'P')
				overlay_img(&img, "./textures/dirt64.xpm",
					"./textures/steve_prof2.xpm", game);
			else if (game->map[img.x_pos][img.y_pos] == 'C')
				overlay_img(&img, "./textures/dirt64.xpm",
					"./textures/diamond.xpm", game);
			img.y_pos++;
		}
		img.x_pos++;
	}
}
