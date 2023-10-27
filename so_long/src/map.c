/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:55:07 by asangerm          #+#    #+#             */
/*   Updated: 2023/10/27 17:20:28 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(char *file)
{
	char	*line;
	int		size;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	size = ft_strlen(line);
	ft_printf("%d\n", size);
	ft_printf("%s\n", line);
	close(fd);
	return ;
}