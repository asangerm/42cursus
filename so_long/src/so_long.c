/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:00 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/05 18:46:32 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		i++;
	}
}

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

void	game_init(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_path = NULL;
	game->x_map = 0;
	game->y_map = 0;
	game->count = 0;
	game->x_pos_p = 0;
	game->y_pos_p = 0;
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
	map_size(&game);
	game.win = mlx_new_window(game.mlx, game.x_map * 64,
			game.y_map * 64, "My Image Window");
	if (!game.win)
		return (0);
	map_to_tab(&game);
	display_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
