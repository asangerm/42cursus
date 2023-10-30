/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:00 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/30 20:15:32 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		i++;
	}
}

void	display_map(char **map, int h, int w, void *mlx, void *win)
{
	int		i;
	int		j;
	int		width;
	int		height;
	void	*back;
	void	*steve;
	
	i = 0;
	j = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			if (map[i][j] == '1')
			{
				back = mlx_xpm_file_to_image(mlx, "./textures/bedrock64.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, back, j*64, i*64);
			}
			else if (map[i][j] == '0')
			{
				back = mlx_xpm_file_to_image(mlx, "./textures/dirt64.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, back, j*64, i*64);
			}
			else if (map[i][j] == 'E')
			{
				back = mlx_xpm_file_to_image(mlx, "./textures/nether_portal64.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, back, j*64, i*64);
			}
			else if (map[i][j] == 'P')
			{
				back = mlx_xpm_file_to_image(mlx, "./textures/dirt64.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, back, j*64, i*64);
				steve = mlx_xpm_file_to_image(mlx, "./textures/steve_prof2.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, steve, j*64, i*64);
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void		*mlx;
	void		*win;
	char		**map;
	t_size_m	size_m;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	win = mlx_new_window(mlx, 2500, 1000, "My Image Window");
	if (!win)
		return (0);
	size_m = map_size("./map/map.ber");
	map = map_to_tab("./map/map.ber", size_m);
	display_map(map, size_m.h, size_m.w, mlx, win);
	//ft_printf("\nhauteur : %d, largeur : %d\n", size_m.h, size_m.w);
	mlx_loop(mlx);
	return (0);
}
