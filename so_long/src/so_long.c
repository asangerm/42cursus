/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:00 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/14 01:01:22 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error invalid number of arguments\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error invalid argument\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	nb_char(t_game *game, char c)
{
	t_axes	i;
	int		count;

	i.y = 0;
	count = 0;
	while (i.y < game->map_dim.y)
	{
		i.x = 0;
		while (i.x < game->map_dim.x)
		{
			if (game->map[i.y][i.x] == c)
				count++;
			i.x++;
		}
		i.y++;
	}
	return (count);
}

void	destroy(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->text.dirt.img);
	mlx_destroy_image(game->mlx, game->text.bedrock.img);
	mlx_destroy_image(game->mlx, game->text.steve.img);
	mlx_destroy_image(game->mlx, game->text.diamond.img);
	mlx_destroy_image(game->mlx, game->text.book.img);
	mlx_destroy_image(game->mlx, game->text.zombie.img);
	while (i < 8)
	{
		mlx_destroy_image(game->mlx, game->text.portal[i].img);
		i++;
	}
	free(game->text.portal);
}

void	end(t_game *game)
{
	int		i;

	i = 0;
	if (game->map != NULL)
	{
		while (game->map[i] != NULL)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free(game->c_pos);
	free(game->z_pos);
	destroy(game);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_args(argc, argv))
		return (0);
	game.map_path = argv[1];
	game.mlx = mlx_init();
	game_init(&game);
	if (!game.mlx)
		return (0);
	game.map = str_to_tab(file_to_str(&game));
	game.map_dim = map_size(&game);
	game.win = mlx_new_window(game.mlx, game.map_dim.x * 64,
			game.map_dim.y * 64, "So_long");
	if (!game.win)
		return (0);
	game_init2(&game);
	image_init2(&game);
	check_map(&game);
	display_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.mlx, anime_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
