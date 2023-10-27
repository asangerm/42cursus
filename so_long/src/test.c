/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:00 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/24 19:28:59 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    void *mlx;
    void *win;
    void *img;
	int width;
    int height;
	int i;
	int j;

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
	i = width/4;
	j = height/4;

	img = mlx_xpm_file_to_image(mlx, "./textures/steve.xpm", &width, &height);
	if (!img)
		return (0);
	ft_printf("Avant mlx_put_img_to_win\n");
    mlx_put_image_to_window(mlx, win, img, i, j);
	i = width;
	j = height;


    mlx_loop(mlx);

    return (0);
}
