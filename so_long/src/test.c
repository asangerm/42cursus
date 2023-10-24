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

# define WIN_W 1920
# define WIN_H 1080
# define MLX_ERROR 1

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		j;
	t_data	img;

	i = 0;
	j = 0;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
        return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "so_long");
	 if (win_ptr == NULL)
    {
        free(mlx_ptr);
        return (MLX_ERROR);
    }
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i <= WIN_W && j <= WIN_H)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i++;
		j++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
