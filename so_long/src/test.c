/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:00 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/27 17:20:50 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
}

int	main(void)
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	int			i;
	int			j;
	t_size_m	size_m;

	ft_printf("Avant mlx\n");
	mlx = mlx_init();
	if (!mlx)
		return (0);
	ft_printf("Avant win\n");
	win = mlx_new_window(mlx, 800, 600, "My Image Window");
	if (!win)
		return (0);
	ft_printf("Avant img\n");
	img = mlx_xpm_file_to_image(mlx, "./textures/dirt.xpm", &width, &height);
	if (!img)
		return (0);
	ft_printf("Avant mlx_put_img_to_win\n");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	i = width / 4;
	j = height / 4;
	img = mlx_xpm_file_to_image(mlx, "./textures/steve.xpm", &width, &height);
	if (!img)
		return (0);
	ft_printf("Avant mlx_put_img_to_win\n");
	mlx_put_image_to_window(mlx, win, img, i, j);
	i = width;
	j = height;
	size_m = map_size("./map/map.ber");
	ft_put_tab(map_to_tab("./map/map.ber", size_m));
	ft_printf("hauteur : %d, largeur : %d\n", size_m.h, size_m.w);
	mlx_loop(mlx);
	return (0);
}
