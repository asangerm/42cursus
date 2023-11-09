/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:57:01 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/09 01:20:44 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_point(t_axes point, t_game *game)
{
	if (point.x >= 0 && point.x < game->map_dim.x)
		if (point.y >= 0 && point.y < game->map_dim.y)
			if (game->map[point.y][point.x] != '1')
				return (1);
	return (0);
}

int	dfs(t_axes pos, t_axes end, t_game *game, int **visited)
{
	t_axes	nexts[4];
	t_axes	next;
	int		i;

	if (pos.x == end.x && pos.y == end.y)
		return (1);
	visited[pos.y][pos.x] = 1;
	nexts[0] = (t_axes){pos.x, pos.y - 1};
	nexts[1] = (t_axes){pos.x, pos.y + 1};
	nexts[2] = (t_axes){pos.x - 1, pos.y};
	nexts[3] = (t_axes){pos.x + 1, pos.y};
	i = 0;
	while (i < 4)
	{
		next = nexts[i];
		if (is_valid_point(next, game) && !visited[next.y][next.x])
			if (dfs(next, end, game, visited))
				return (1);
		i++;
	}
	return (0);
}

void	destroy_visited(int **visited, t_game *game)
{
	int		i;

	i = 0;
	if (visited != NULL)
	{
		while (i < game->map_dim.y)
		{
			free(visited[i]);
			i++;
		}
	}
	free(visited);
}

int	path_exist(t_axes start, t_axes end, t_game *game)
{
	int		**visited;
	t_axes	i;
	int		result;

	visited = malloc(game->map_dim.y * sizeof(int *));
	i.y = 0;
	while (i.y < game->map_dim.y)
	{
		i.x = 0;
		visited[i.y] = malloc(game->map_dim.x * sizeof(int));
		while (i.x < game->map_dim.x)
		{
			visited[i.y][i.x] = 0;
			i.x++;
		}
		i.y++;
	}
	result = dfs(start, end, game, visited);
	destroy_visited(visited, game);
	return (result);
}
