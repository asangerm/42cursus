/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:56:52 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/08 17:31:46 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game *game)
{
	t_axes	size;
	t_axes	i;

	i.y = 0;
	size = game->map_dim;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			if (i.y == 0 || i.y == size.y - 1 || i.x == 0 || i.x == size.x - 1)
			{
				if (game->map[i.y][i.x] != '1')
					return (0);
			}
			i.x++;
		}
		i.y++;
	}
	return (1);
}

void	check_map(t_game *game)
{
	if (!check_wall(game))
		ft_error("Error map not closed", game);
}
