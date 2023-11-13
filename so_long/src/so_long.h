/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/11/13 14:47:04 by asangerm         ###   ########.fr       */
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
# define BOOK "./textures/book.xpm"
# define ZOMBIE "./textures/zombie.xpm"

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

typedef struct s_img
{
	void	*img;
	int		h;
	int		w;
	char	*path;
	char	*data;
	int		endian;
	int		bpp;
	int		size_line;
}			t_img;

typedef struct s_text
{
	t_img	dirt;
	t_img	bedrock;
	t_img	steve;
	t_img	diamond;
	t_img	portal;
	t_img	book;
	t_img	zombie;
}			t_text;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*map_path;
	t_text	text;
	t_axes	map_dim;
	int		nb_diamond;
	int		nb_zombie;
	int		count;
	t_axes	p_pos;
	t_axes	e_pos;
	t_axes	*z_pos;
	t_axes	*c_pos;
}		t_game;

void	end(t_game *game);
void	move_up(t_game *game);
t_axes	map_size(t_game *game);
void	coords_p(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
char	**str_to_tab(char *str);
void	check_map(t_game *game);
void	game_init(t_game *game);
void	image_init(t_game *game);
void	move_right(t_game *game);
void	display_map(t_game *game);
void	zombie_move(t_game *game);
char	*file_to_str(t_game *game);
int		close_window(t_game *game);
void	display_moves(t_game *game);
int		nb_char(t_game *game, char c);
void	ft_error(char *str, t_game *game);
void	move(t_game *game, t_axes new_pos);
int		key_hook(int keybind, t_game *game);
void	reload(t_game *game, t_axes new_pos);
void	print_img(t_img text, t_game *game, t_axes i);
int		path_exist(t_axes start, t_axes end, t_game *game);
void	merge_img(t_img bg, t_img fg, t_game *game, t_axes i);
void	overlay_img(t_img fg, t_img bg, t_game *game, t_axes i);

#endif