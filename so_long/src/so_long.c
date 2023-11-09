/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:00 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/09 01:51:01 by asangerm         ###   ########.fr       */
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

static void	game_init(t_game *game)
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
	mlx_destroy_image(game->mlx, game->text.dirt.img);
	mlx_destroy_image(game->mlx, game->text.bedrock.img);
	mlx_destroy_image(game->mlx, game->text.steve.img);
	mlx_destroy_image(game->mlx, game->text.diamond.img);
	mlx_destroy_image(game->mlx, game->text.portal.img);
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
	game.nb_diamond = nb_char(&game, 'C');
	game.c_pos = malloc(sizeof(t_axes) * game.nb_diamond);
	check_map(&game);
	display_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
