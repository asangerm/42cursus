/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:32:50 by asangerm          #+#    #+#             */
/*   Updated: 2023/12/19 13:33:20 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	print(t_data *data, int nb, char *str)
{
	pthread_mutex_lock(&(data->writer));
	if (!(data->e_dead))
		printf("%4lli %i %s\n", get_time() - data->start_time, nb, str);
	pthread_mutex_unlock(&(data->writer));
}

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
