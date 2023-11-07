/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/07 17:09:08 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/src/libft.h"
# include "../minilibx-linux/mlx.h"

# define BEDROCK "./textures/bedrock.xpm"
# define STEVE "./textures/steve.xpm"
# define DIAMOND "./textures/diamond.xpm"
# define DIRT "./textures/dirt.xpm"
# define PORTAL "./textures/portal.xpm"

# define K_UP 119
# define K_DOWN 115
# define K_LEFT 97
# define K_RIGHT 100
# define K_ECHAP 65307

typedef struct s_axes
{
	int	x;
	int	y;
}			t_axes;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*map_path;
	t_axes	map_dim;
	int		nb_diamond;
	int		count;
	t_axes	p_pos;
}		t_game;

typedef struct s_img
{
	void	*img;
	t_axes	img_dim;
	char	*texture;
	t_axes	img_pos;
	char	*data;
	int		endian;
	int		bpp;
	int		size_line;
}			t_img;

void	end(t_game *game);
void	map_size(t_game *game);
void	move_up(t_game *game);
void	coords_p(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	display_map(t_game *game);
char	**map_to_tab(t_game *game);
void	move(t_game *game, t_axes new_pos);
int		key_hook(int keybind, t_game *game);
void	reload(t_game *game, t_axes new_pos);
void	merge_img(t_img *img, t_img *fg, t_game *game);
void	print_img(t_img *img, char *path, t_game *game);
void	overlay_img(t_img *img, char *pathb, char *pathf, t_game *game);

#endif