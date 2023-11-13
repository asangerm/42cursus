/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:53:52 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/13 11:45:56 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->count);
	overlay_img(game->text.book, game->text.bedrock, game, (t_axes){0,0});
	mlx_string_put(game->mlx, game->win, 26, 35, 0x000000, str);
	free(str);
}
