/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:39 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/27 17:08:51 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/src/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_size_m
{
	size_t	h;
	size_t	w;
}				t_size_m;

t_size_m	map_size(char *file);
char		**map_to_tab(char *file, t_size_m size_m);

#endif