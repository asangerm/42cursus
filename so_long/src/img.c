/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:08:58 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/13 13:53:49 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_img text, t_game *game, t_axes i)
{
	mlx_put_image_to_window(game->mlx, game->win, text.img,
		i.x * 64, i.y * 64);
}

void	merge_img(t_img bg, t_img fg, t_game *game, t_axes i)
{
	t_axes	j;

	j.y = 0;
	while (j.y < bg.h)
	{
		j.x = 0;
		while (j.x < bg.w)
		{
			if (fg.data[(j.y * fg.size_line) + (j.x * (fg.bpp / 8))] != 0)
			{
				bg.data[(j.y * bg.size_line) + (j.x * (bg.bpp / 8))]
					= fg.data[(j.y * fg.size_line) + (j.x * (fg.bpp / 8))];
				bg.data[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 1)]
					= fg.data[(j.y * fg.size_line) + (j.x * (fg.bpp / 8) + 1)];
				bg.data[(j.y * bg.size_line) + (j.x * (bg.bpp / 8) + 2)]
					= fg.data[(j.y * fg.size_line) + (j.x * (fg.bpp / 8) + 2)];
			}
			j.x++;
		}
		j.y++;
	}
	print_img(bg, game, i);
	mlx_destroy_image(game->mlx, bg.img);
}

void	overlay_img(t_img fg, t_img bg, t_game *game, t_axes i)
{
	t_img	back;

	back.img = mlx_xpm_file_to_image(game->mlx, bg.path, &back.w, &back.h);
	fg.data = mlx_get_data_addr(fg.img, &fg.bpp, &fg.size_line, &fg.endian);
	back.data = mlx_get_data_addr(back.img, &back.bpp, &back.size_line,
			&back.endian);
	merge_img(back, fg, game, i);
}

void	display_map(t_game *game)
{
	t_axes	i;

	i.y = 0;
	while (i.y < game->map_dim.y)
	{
		i.x = 0;
		while (i.x < game->map_dim.x)
		{
			if (game->map[i.y][i.x] == '1')
				print_img(game->text.bedrock, game, i);
			else if (game->map[i.y][i.x] == '0')
				print_img(game->text.dirt, game, i);
			else if (game->map[i.y][i.x] == 'E')
				print_img(game->text.portal, game, i);
			else if (game->map[i.y][i.x] == 'P')
				overlay_img(game->text.steve, game->text.dirt, game, i);
			else if (game->map[i.y][i.x] == 'C')
				overlay_img(game->text.diamond, game->text.dirt, game, i);
			else if (game->map[i.y][i.x] == 'Z')
				overlay_img(game->text.zombie, game->text.dirt, game, i);
			i.x++;
		}
		i.y++;
	}
}
