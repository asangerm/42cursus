/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/04 21:01:58 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/src/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		x_win;
	int		y_win;
	char	**map;
	char	*map_path;
	int		x_map;
	int		y_map;
	int		count;
	int		x_pos_p;
	int		y_pos_p;	
}				t_game;

typedef struct s_img
{
	void	*img;
	int		x_img;
	int		y_img;
	char	*texture;
	int		x_pos;
	int		y_pos;
	char	*data;
	int		endian;
	int		bpp;
	int		size_line;
}			t_img;

int			key_hook(int keybind, t_game *game);
void		map_size(t_game *game);
void		map_to_tab(t_game *game);
void		display_map(t_game *game);

#endif