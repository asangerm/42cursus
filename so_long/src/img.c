/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:08:58 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/02 22:11:10 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_img(t_img *img, char *path, t_game *game)
{
	img->texture = path;
	img->img = mlx_xpm_file_to_image(game->mlx, img->texture,
			&img->x_img, &img->y_img);
	mlx_put_image_to_window(game->mlx, game->win, img->img,
		img->y_win * 64, img->x_win * 64);
}

static void	merge_img(t_img *img, t_img *fg, t_game *game)
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
		img->y_win * 64, img->x_win * 64);
}

static void	overlay_img(t_img *img, char *pathb, char *pathf, t_game *game)
{
	t_img	fg;

	fg.texture = pathf;
	fg.img = mlx_xpm_file_to_image(game->mlx, fg.texture,
			&fg.x_img, &fg.y_img);
	fg.x_win = img->x_win;
	fg.y_win = img->y_win;
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

	img.x_win = 0;
	while (img.x_win < game->y_map)
	{
		img.y_win = 0;
		while (img.y_win < game->x_map)
		{
			if (game->map[img.x_win][img.y_win] == '1')
				print_img(&img, "./textures/bedrock64.xpm", game);
			else if (game->map[img.x_win][img.y_win] == '0')
				print_img(&img, "./textures/dirt64.xpm", game);
			else if (game->map[img.x_win][img.y_win] == 'E')
				print_img(&img, "./textures/nether_portal64.xpm", game);
			else if (game->map[img.x_win][img.y_win] == 'P')
			{
				overlay_img(&img, "./textures/dirt64.xpm",
					"./textures/steve_prof2.xpm", game);
			}
			img.y_win++;
		}
		img.x_win++;
	}
}
