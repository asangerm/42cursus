/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:00 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/07 15:39:43 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Invalid argument\n");
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
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_path = NULL;
	game->map_dim.x = 0;
	game->map_dim.y = 0;
	game->nb_diamond = 0;
	game->count = 0;
	game->p_pos.x = 0;
	game->p_pos.y = 0;
}

void	end(t_game *game)
{
	free(game->map);
	mlx_loop_end(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_args(argc, argv))
		return (0);
	game_init(&game);
	game.map_path = argv[1];
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.map_dim = map_size(game.map_path);
	game.win = mlx_new_window(game.mlx, game.map_dim.x * 64,
			game.map_dim.y * 64, "So_long");
	if (!game.win)
		return (0);
	game.map = map_to_tab(&game);
	game.nb_diamond = nb_char(&game, 'C');
	display_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
